"""Native tests of the ACTUAL C fallback bodies in src/game/math.c.

The original GBA build still uses the ASM through NONMATCH. This test extracts
the five newly written C implementations, compiles them with the host C
compiler and independently checks their fixed-point behavior against formulas
transcribed from the ASM. It DOES NOT establish agbcc/ROM byte matching.
"""

import ctypes
import math
import os
import random
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / "src/game/math.c"
FUNCTIONS = (
    "sa2__unused_sub_8083858",
    "sa2__unused_sub_8083A48",
    "sa2__unused_sub_8083B10",
    "sa2__unused_sub_8084EAC",
    "sa2__unused_sub_8085314",
)
C_HEADER = r"""
#include <math.h>
#include <stdint.h>
typedef int16_t s16;
typedef int32_t s32;
typedef uint16_t u16;
typedef struct {
    s16 unk0, unk2, unk4, unk6;
    u16 unk8, unkA, unkC, unkE, unk10, unk12;
    uint32_t unk14, unk18, unk1C;
} UNK_8085D14;
struct UNK_8085F1C_1 {
    s16 unk0, unk2[9];
    s32 unk14, unk18, unk1C;
};
u16 Sqrt(uint32_t v) { return (u16)sqrt((double)v); }
#define NONMATCH(path, decl) decl
#define END_NONMATCH
"""


class Rotation(ctypes.Structure):
    _fields_ = [(f"unk{x}", ctypes.c_int16) for x in (0, 2, 4, 6)] + [
        (f"unk{x}", ctypes.c_uint16) for x in ("8", "A", "C", "E", "10", "12")
    ] + [(f"unk{x}", ctypes.c_uint32) for x in ("14", "18", "1C")]


class Matrix(ctypes.Structure):
    _fields_ = [
        ("unk0", ctypes.c_int16),
        ("unk2", ctypes.c_int16 * 9),
        ("unk14", ctypes.c_int32),
        ("unk18", ctypes.c_int32),
        ("unk1C", ctypes.c_int32),
    ]


def signed16(value):
    return ((value + 0x8000) & 0xFFFF) - 0x8000


def get_components(rot):
    return tuple(getattr(rot, f"unk{x}") for x in (0, 2, 4, 6))


def rotation(values):
    obj = Rotation()
    for name, value in zip(("unk0", "unk2", "unk4", "unk6"), values):
        setattr(obj, name, value)
    return obj


def extract_asm_fallbacks(source):
    """Extract real NONMATCH C definitions without copying them into fixtures."""
    parts = []
    for name in FUNCTIONS:
        begin = source.index(f'NONMATCH("asm/non_matching/game/math/{name}.inc"')
        end = source.index("END_NONMATCH", begin) + len("END_NONMATCH")
        part = source[begin:end]
        if not part.count("NONMATCH(") == 1:
            raise AssertionError(f"Nested fallback around {name}")
        if part.count("{") != part.count("}") or "()" in part.split("{", 1)[0]:
            raise AssertionError(f"Missing typed C implementation: {name}")
        parts.append(part)
    return "\n\n".join(parts)


def normalized_reference(values, conjugate=False):
    # ASM: sum of 4 s16 squares; GBA Sqrt; 0x100000/(u16)Sqrt;
    # multiply each original s16 by factor, >>10, truncate to s16.
    magnitude = math.isqrt(sum(x * x for x in values))
    if magnitude == 0:
        raise ValueError("Original ARM divides by zero for a zero-length rotation")
    factor = 0x100000 // (magnitude & 0xFFFF)
    return tuple(signed16((factor * x * (-1 if conjugate and i < 3 else 1)) >> 10)
                 for i, x in enumerate(values))


def multiply_reference(a, b):
    # Original ASM stores the product into the second quaternion, in place.
    w, x, y, z = a
    p, q, r, s = b
    return tuple(map(signed16, (
        (z * p + w * s + x * r - y * q) >> 10,
        (z * q - w * r + x * s + y * p) >> 10,
        (z * r + w * q - x * p + y * s) >> 10,
        (z * s - w * p - x * q - y * r) >> 10,
    )))


def matrix_reference(q):
    # Assemble each term in the same fixed-point order as the Thumb original.
    w, x, y, z = q
    def term(a, b):
        return (a * 2 * b * 64) >> 16
    xx, yy, ww = term(x, x), term(y, y), term(w, w)
    wx, wy, wz = term(w, x), term(w, y), term(w, z)
    xy, yz, xz = term(x, y), term(y, z), term(x, z)
    return tuple(map(signed16, (
        0x400 - xx - yy, wx - yz, wy + xz,
        wx + yz, 0x400 - ww - yy, xy - wz,
        wy - xz, xy + wz, 0x400 - ww - xx,
    )))


class MathFallbackNativeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        compiler = shutil.which(os.environ.get("CC", "cc"))
        if compiler is None:
            raise unittest.SkipTest("No host C compiler available")
        cls.tmp = tempfile.TemporaryDirectory(prefix="sa3-native-math-")
        location = Path(cls.tmp.name)
        original = SOURCE.read_text(encoding="utf-8")
        (location / "math_fallbacks.c").write_text(
            C_HEADER + extract_asm_fallbacks(original) + "\n", encoding="utf-8")
        output = location / "math_fallbacks.so"
        result = subprocess.run([
            compiler, "-std=c99", "-O2", "-fwrapv", "-Wall", "-Wextra",
            "-Werror", "-fPIC", "-shared", str(location / "math_fallbacks.c"),
            "-o", str(output), "-lm",
        ], capture_output=True, text=True)
        if result.returncode:
            raise AssertionError("Native C fallback did not compile:\n" + result.stderr)
        cls.library = ctypes.CDLL(str(output))
        for name, arity, type_ in (
            ("sa2__sub_8083858", 1, Rotation),
            ("sa2__sub_8083A48", 2, Rotation),
            ("sa2__sub_8083B10", 1, Rotation),
            ("sa2__sub_8084EAC", 1, Matrix),
            ("sa2__sub_8085314", 2, Matrix),
        ):
            fn = getattr(cls.library, name)
            fn.argtypes = [ctypes.POINTER(type_)] * arity
            fn.restype = None

    @classmethod
    def tearDownClass(cls):
        if hasattr(cls, "tmp"):
            cls.tmp.cleanup()

    def test_normalize_300_rotations(self):
        rng = random.Random(0x534133)
        for _ in range(300):
            values = [rng.randrange(-900, 901) for _ in range(4)]
            if values == [0] * 4:
                values[0] = 1
            actual = rotation(values)
            self.library.sa2__sub_8083858(ctypes.byref(actual))
            self.assertEqual(get_components(actual), normalized_reference(values))

    def test_conjugate_normalize_300_rotations(self):
        rng = random.Random(0xAC3B10)
        for _ in range(300):
            values = [rng.randrange(-900, 901) for _ in range(4)]
            if values == [0] * 4:
                values[3] = 1
            actual = rotation(values)
            self.library.sa2__sub_8083B10(ctypes.byref(actual))
            self.assertEqual(get_components(actual),
                             normalized_reference(values, conjugate=True))

    def test_multiply_400_rotations(self):
        rng = random.Random(0x83A48)
        for _ in range(400):
            a = [rng.randrange(-1024, 1025) for _ in range(4)]
            b = [rng.randrange(-1024, 1025) for _ in range(4)]
            left, right = rotation(a), rotation(b)
            self.library.sa2__sub_8083A48(ctypes.byref(left), ctypes.byref(right))
            self.assertEqual(get_components(right), multiply_reference(a, b))
            self.assertEqual(get_components(left), tuple(a))

    def test_transpose_300_matrices_and_preserve_other_fields(self):
        rng = random.Random(0x4EAC)
        for _ in range(300):
            m = Matrix()
            m.unk0 = rng.randrange(-30000, 30000)
            m.unk14, m.unk18, m.unk1C = 17, -23, 42
            before = [rng.randrange(-30000, 30000) for _ in range(9)]
            for i, x in enumerate(before):
                m.unk2[i] = x
            self.library.sa2__sub_8084EAC(ctypes.byref(m))
            expected = before.copy()
            for a, b in ((1, 3), (2, 6), (5, 7)):
                expected[a], expected[b] = expected[b], expected[a]
            self.assertEqual(list(m.unk2), expected)
            self.assertEqual((m.unk14, m.unk18, m.unk1C), (17, -23, 42))

    def test_rotation_to_matrix_300_cases(self):
        rng = random.Random(0x5314)
        for _ in range(300):
            q = [rng.randrange(-1024, 1025) for _ in range(4)]
            src, dst = Matrix(), Matrix()
            src.unk0 = q[0]
            for i in range(3):
                src.unk2[i] = q[i + 1]
            dst.unk14, dst.unk18, dst.unk1C = 17, 19, 23
            self.library.sa2__sub_8085314(ctypes.byref(dst), ctypes.byref(src))
            self.assertEqual(tuple(dst.unk2), matrix_reference(q))
            self.assertEqual((dst.unk14, dst.unk18, dst.unk1C), (0, 0, 0))


if __name__ == "__main__":
    unittest.main()
