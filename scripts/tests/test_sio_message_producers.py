"""Guard reconstructed SIO event producers against out-of-bounds queue reads.

The five-byte SIO queue copies offsets 0..4. Original callers write only a
subset of bytes to their four-byte stack frames, so those trailing bytes are
not yet reconstructed for binary matching. Host-side C must nevertheless
provide a readable fifth byte.
"""
from pathlib import Path
import re
import unittest

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / "src/sio_stuff_x.c"
PRODUCERS = {
    "8027658": (0x38, 0x05),
    "802785C": (0x38, 0x21),
    "80278DC": (0x38, 0x03),
    "802773C": (0x38, 0x07),
}


class SioMessageProducers(unittest.TestCase):
    def test_queue_consumes_five_bytes(self):
        source = SOURCE.read_text(encoding="utf-8")
        start = source.index('NONMATCH("asm/non_matching/sio/sio__sub_8026AB8.inc"')
        end = source.index("END_NONMATCH", start)
        queue = source[start:end]
        for idx in range(5):
            self.assertIn("packet[" + str(idx) + "]", queue)

    def test_reconstructed_producers_provide_five_bytes(self):
        source = SOURCE.read_text(encoding="utf-8")
        for address, header in PRODUCERS.items():
            with self.subTest(address=address):
                start = source.index(
                    'NONMATCH("asm/non_matching/sio/sio__sub_'
                    + address + '.inc"'
                )
                end = source.index("END_NONMATCH", start)
                implementation = source[start:end]
                self.assertIn("u8 packet[5];", implementation)
                self.assertIn("sub_8026AB8(packet);", implementation)
                for i, value in enumerate(header):
                    pattern = r"packet\[" + str(i) + r"\]\s*=\s*(0x[0-9a-fA-F]+|\d+);"
                    match = re.search(pattern, implementation)
                    self.assertIsNotNone(match)
                    self.assertEqual(int(match.group(1), 0), value)

    def test_source_assembly_event_codes(self):
        for address, header in PRODUCERS.items():
            asm = (ROOT / "asm/non_matching/sio/sio__sub_"
                   / (address + ".inc"))
            # The source files are named sio__sub_802xxxx.inc.
            asm = ROOT / "asm/non_matching/sio" / ("sio__sub_" + address + ".inc")
            source = asm.read_text(encoding="utf-8")
            self.assertIn("bl sub_8026AB8", source)
            self.assertIn("movs r0, #0x38", source)
            self.assertIn("movs r0, #" + hex(header[1]), source)


if __name__ == "__main__":
    unittest.main()
