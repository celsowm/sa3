"""Native tests of the ACTUAL C fallback bodies in src/game/math.c.

The original GBA build still uses the ASM through NONMATCH. This test extracts
the newly written C implementations, compiles them with the host C
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
    "sa2__sub_8083B88",
    "sa2__unused_sub_8083E44",
    "sa2__unused_sub_8084090",
    "sa2__unused_sub_80842E4",
    "sa2__unused_sub_808442C",
    "sa2__unused_sub_808477C",
    "sa2__unused_sub_8084EE0",
    "sa2__unused_sub_80851E0",
)
C_HEADER = r"""
#include <math.h>
#include <stdint.h>
#include <string.h>
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
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
            ("sa2__sub_8083B88", 3, Matrix),
            ("sa2__sub_8083E44", 2, Matrix),
            ("sa2__sub_8084090", 2, Matrix),
            ("sa2__sub_80851E0", 1, Matrix),
            ("sa2__sub_8084EE0", 1, Matrix),
        ):
            fn = getattr(cls.library, name)
            fn.argtypes = [ctypes.POINTER(type_)] * arity
            fn.restype = None
        vector_fn = cls.library.sa2__sub_80842E4
        vector_fn.argtypes = [ctypes.POINTER(ctypes.c_int32), ctypes.POINTER(Matrix),
                              ctypes.POINTER(ctypes.c_int32)]
        vector_fn.restype = None
        in_place_vector_fn = cls.library.sa2__sub_808442C
        in_place_vector_fn.argtypes = [ctypes.POINTER(ctypes.c_int32),
                                        ctypes.POINTER(Matrix)]
        in_place_vector_fn.restype = None
        project_fn = cls.library.sa2__sub_808477C
        project_fn.argtypes = [ctypes.POINTER(Matrix), ctypes.POINTER(ctypes.c_int32)]
        project_fn.restype = None

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


    def test_affine_matrix_composition_1000_cases(self):
        """ASM row/column multiplication plus 64-bit translated origin."""
        rng = random.Random(0x3B88)
        for _ in range(1000):
            a, b, c = Matrix(), Matrix(), Matrix()
            for idx in range(9):
                a.unk2[idx] = rng.randrange(-1024, 1025)
                b.unk2[idx] = rng.randrange(-1024, 1025)
            for name in ("unk14", "unk18", "unk1C"):
                setattr(a, name, rng.randrange(-200000, 200001))
                setattr(b, name, rng.randrange(-200000, 200001))
            a_basis = tuple(a.unk2)
            b_basis = tuple(b.unk2)
            a_translation = (a.unk14, a.unk18, a.unk1C)
            b_translation = (b.unk14, b.unk18, b.unk1C)

            self.library.sa2__sub_8083B88(
                ctypes.byref(a), ctypes.byref(b), ctypes.byref(c))

            expected_basis = [
                signed16(sum(a_basis[row * 3 + k] * b_basis[k * 3 + column]
                             for k in range(3)) >> 10)
                for row in range(3) for column in range(3)
            ]
            expected_translation = [
                (sum(a_translation[k] * b_basis[k * 3 + col]
                     for k in range(3)) + b_translation[col]) >> 10
                for col in range(3)
            ]
            self.assertEqual(list(c.unk2), expected_basis)
            self.assertEqual(
                (c.unk14, c.unk18, c.unk1C), tuple(expected_translation))
            self.assertEqual(tuple(a.unk2), a_basis)
            self.assertEqual(tuple(b.unk2), b_basis)


    def test_in_place_affine_product_lhs_500_cases(self):
        """8083E44 overwrites lhs row-by-row, leaving rhs unchanged."""
        rng = random.Random(0x3E44)
        for _ in range(500):
            a, b = Matrix(), Matrix()
            for i in range(9):
                a.unk2[i] = rng.randrange(-1100, 1101)
                b.unk2[i] = rng.randrange(-1100, 1101)
            for key in ("unk14", "unk18", "unk1C"):
                setattr(a, key, rng.randrange(-200000, 200001))
                setattr(b, key, rng.randrange(-200000, 200001))
            ab, bb = list(a.unk2), list(b.unk2)
            at = (a.unk14, a.unk18, a.unk1C)
            bt = (b.unk14, b.unk18, b.unk1C)
            self.library.sa2__sub_8083E44(ctypes.byref(a), ctypes.byref(b))
            expected_basis = [
                signed16(sum(ab[row * 3 + k] * bb[k * 3 + col]
                             for k in range(3)) >> 10)
                for row in range(3) for col in range(3)
            ]
            expected_t = [
                (sum(at[k] * bb[k * 3 + col] for k in range(3)) + bt[col]) >> 10
                for col in range(3)
            ]
            self.assertEqual(list(a.unk2), expected_basis)
            self.assertEqual((a.unk14, a.unk18, a.unk1C), tuple(expected_t))
            self.assertEqual(list(b.unk2), bb)

    def test_in_place_affine_product_rhs_500_cases(self):
        """8084090 writes output column by column, retaining each source."""
        rng = random.Random(0x4090)
        for _ in range(500):
            a, b = Matrix(), Matrix()
            for i in range(9):
                a.unk2[i] = rng.randrange(-1000, 1001)
                b.unk2[i] = rng.randrange(-1000, 1001)
            for key in ("unk14", "unk18", "unk1C"):
                setattr(a, key, rng.randrange(-100000, 100001))
                setattr(b, key, rng.randrange(-100000, 100001))
            ab, bb = list(a.unk2), list(b.unk2)
            at = (a.unk14, a.unk18, a.unk1C)
            bt = (b.unk14, b.unk18, b.unk1C)
            self.library.sa2__sub_8084090(ctypes.byref(a), ctypes.byref(b))
            self.assertEqual(list(b.unk2), [
                signed16(sum(ab[row * 3 + k] * bb[k * 3 + col]
                             for k in range(3)) >> 10)
                for row in range(3) for col in range(3)
            ])
            self.assertEqual((b.unk14, b.unk18, b.unk1C), tuple(
                (sum(at[k] * bb[k * 3 + col] for k in range(3)) + bt[col]) >> 10
                for col in range(3)
            ))
            self.assertEqual(list(a.unk2), ab)

    def test_transform_vector_500_cases(self):
        rng = random.Random(0x42E4)
        for _ in range(500):
            vec = [rng.randrange(-100000, 100001) for _ in range(3)]
            matrix = Matrix()
            for i in range(9):
                matrix.unk2[i] = rng.randrange(-1200, 1201)
            for key in ("unk14", "unk18", "unk1C"):
                setattr(matrix, key, rng.randrange(-500000, 500001))
            vec_in = (ctypes.c_int32 * 3)(*vec)
            vec_out = (ctypes.c_int32 * 3)()
            self.library.sa2__sub_80842E4(ctypes.cast(vec_in, ctypes.POINTER(ctypes.c_int32)),
                                            ctypes.byref(matrix), vec_out)
            translation = [matrix.unk14, matrix.unk18, matrix.unk1C]
            expected = [
                (sum(vec[k] * matrix.unk2[k * 3 + col] for k in range(3))
                 + translation[col]) >> 10
                for col in range(3)
            ]
            self.assertEqual(list(vec_out), expected)
            self.assertEqual(list(vec_in), vec)

    def test_inverse_affine_500_cases(self):
        rng = random.Random(0x51E0)
        for _ in range(500):
            mat = Matrix()
            for i in range(9):
                mat.unk2[i] = rng.randrange(-1024, 1025)
            for key in ("unk14", "unk18", "unk1C"):
                setattr(mat, key, rng.randrange(-100000, 100001))
            basis = list(mat.unk2)
            old_t = (mat.unk14, mat.unk18, mat.unk1C)
            self.library.sa2__sub_80851E0(ctypes.byref(mat))
            transposed = [basis[3 * col + row]
                          for row in range(3) for col in range(3)]
            self.assertEqual(list(mat.unk2), transposed)
            expected_t = [
                sum(-old_t[k] * transposed[k * 3 + col] for k in range(3)) >> 10
                for col in range(3)
            ]
            self.assertEqual((mat.unk14, mat.unk18, mat.unk1C), tuple(expected_t))


    def test_in_place_vector_transform_600_cases(self):
        """808442C uses newly updated X for Y and updated X/Y for Z."""
        rng = random.Random(0x442C)
        for _ in range(600):
            vector = [rng.randrange(-50000, 50001) for _ in range(3)]
            matrix = Matrix()
            for index in range(9):
                matrix.unk2[index] = rng.randrange(-1100, 1101)
            for field in ("unk14", "unk18", "unk1C"):
                setattr(matrix, field, rng.randrange(-150000, 150001))

            values = (ctypes.c_int32 * 3)(*vector)
            self.library.sa2__sub_808442C(values, ctypes.byref(matrix))
            original_x, original_y, original_z = vector
            expected_x = ((original_x * matrix.unk2[0]
                           + original_y * matrix.unk2[3]
                           + original_z * matrix.unk2[6] + matrix.unk14) >> 10)
            expected_y = ((expected_x * matrix.unk2[1]
                           + original_y * matrix.unk2[4]
                           + original_z * matrix.unk2[7] + matrix.unk18) >> 10)
            expected_z = ((expected_x * matrix.unk2[2]
                           + expected_y * matrix.unk2[5]
                           + original_z * matrix.unk2[8] + matrix.unk1C) >> 10)
            self.assertEqual(list(values), [expected_x, expected_y, expected_z])


    def test_project_vector_700_cases(self):
        """808477C: 32-bit wrapped depth and signed 64-bit row dot-products."""
        rng = random.Random(0x477C)
        done = 0
        for _ in range(800):
            xyz = [rng.randrange(-100000, 100001) for _ in range(3)]
            mat = Matrix()
            for k in range(9):
                mat.unk2[k] = rng.randrange(-1000, 1001)
            for name in ("unk14", "unk18", "unk1C"):
                setattr(mat, name, rng.randrange(-10000, 10001))
            t = (mat.unk14, mat.unk18, mat.unk1C)
            raw_depth = (sum(xyz[i] * t[i] for i in range(3)) + 0x100000)
            wrapped = ((raw_depth + 0x80000000) & 0xFFFFFFFF) - 0x80000000
            depth = wrapped >> 10
            if depth == 0:
                continue  # Original Thumb routine would divide by zero.
            scale = (0x100000 // abs(depth)) * (1 if depth > 0 else -1)
            expect = [
                ((sum(xyz[k] * mat.unk2[row * 3 + k] for k in range(3)) >> 10)
                 * scale) >> 10
                for row in range(3)
            ]
            actual = (ctypes.c_int32 * 3)(*xyz)
            self.library.sa2__sub_808477C(ctypes.byref(mat), actual)
            self.assertEqual(list(actual), expect)
            done += 1
        self.assertGreaterEqual(done, 700)


    def test_3x3_inverse_3000_cases_including_original_halfword_writes(self):
        """8084EE0: compare independent adjugate formulas and all 32 bytes."""
        rng = random.Random(0x4EE0)
        completed = 0
        for _ in range(3000):
            matrix = Matrix()
            original = [rng.randrange(-1000, 1001) for _ in range(9)]
            for k, value in enumerate(original):
                matrix.unk2[k] = value
            matrix.unk14 = rng.randrange(-100000, 100001)
            matrix.unk18 = rng.randrange(-100000, 100001)
            matrix.unk1C = rng.randrange(-100000, 100001)
            a, b, c, d, e, f, g, h, i = original
            cofactors = [
                (e * i - f * h) >> 10,
                -((b * i - c * h) >> 10),
                (b * f - c * e) >> 10,
                -((d * i - f * g) >> 10),
                (a * i - c * g) >> 10,
                -((a * f - c * d) >> 10),
                (d * h - e * g) >> 10,
                -((a * h - b * g) >> 10),
                (a * e - b * d) >> 10,
            ]
            determinant = (a * ((e * i - f * h) >> 10)
                           - b * ((d * i - f * g) >> 10)
                           + c * ((d * h - e * g) >> 10))
            if determinant == 0:
                continue  # Original ARM divide-by-zero; not a valid input.
            scale = (0x100000 // abs(determinant)) * (
                1 if determinant > 0 else -1)
            expected_basis = [
                signed16((scale * value) >> 10)
                for value in cofactors
            ]
            expected = bytearray(
                ctypes.string_at(ctypes.byref(matrix), ctypes.sizeof(matrix)))
            for k, value in enumerate(expected_basis):
                expected[2 + k * 2:4 + k * 2] = value.to_bytes(
                    2, "little", signed=True)
            original_translation = (matrix.unk14, matrix.unk18, matrix.unk1C)
            for column in range(3):
                product = sum(
                    original_translation[row] * original[row * 3 + column]
                    for row in range(3))
                halfword = signed16((-product) >> 10)
                expected[0x14 + column * 2:0x16 + column * 2] = (
                    halfword.to_bytes(2, "little", signed=True))
            self.library.sa2__sub_8084EE0(ctypes.byref(matrix))
            actual = ctypes.string_at(ctypes.byref(matrix),
                                      ctypes.sizeof(matrix))
            self.assertEqual(actual, bytes(expected))
            completed += 1
        self.assertGreaterEqual(completed, 2900)


if __name__ == "__main__":
    unittest.main()
