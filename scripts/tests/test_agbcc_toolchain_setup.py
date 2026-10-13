"""ROM-free checks of compiler bootstrap and runner integration."""
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
BOOTSTRAP = ROOT / 'scripts/bootstrap_agbcc.sh'
TOOLCHAIN = ROOT / '.github/workflows/agbcc-toolchain.yml'
BUILD = ROOT / '.github/workflows/build.yml'
SHA = '57a5b3e21157ffa5490deebfa4d6dcf0b3052d28'


class AgbccToolchainSetupTests(unittest.TestCase):
    def test_bootstrap_has_valid_bash_syntax(self):
        subprocess.run(['bash', '-n', str(BOOTSTRAP)], check=True)

    def test_pinned_compiler_and_real_build(self):
        bootstrap = BOOTSTRAP.read_text()
        workflow = TOOLCHAIN.read_text()
        self.assertIn(SHA, bootstrap)
        self.assertIn(SHA, workflow)
        self.assertIn('git -C "$AGBCC_SOURCE_DIR" checkout --detach "$AGBCC_SHA"', bootstrap)
        self.assertIn('./build.sh', bootstrap)
        self.assertIn('./install.sh "$REPO_ROOT"', bootstrap)
        self.assertIn('arm-none-eabi-as', workflow)
        self.assertIn('tools/agbcc/bin/agbcc -O2', workflow)

    def test_rom_not_required_for_compiler_build(self):
        flow = TOOLCHAIN.read_text()
        self.assertIn('workflow_dispatch:', flow)
        self.assertNotIn('secrets.', flow)
        self.assertNotIn('baserom_sa3.gba', flow)
        self.assertIn('upload-artifact@v4', flow)
        self.assertIn('bash scripts/bootstrap_agbcc.sh', BUILD.read_text())

    def test_missing_native_tools_fail_without_network(self):
        with tempfile.TemporaryDirectory() as folder:
            fake_bin = Path(folder)
            (fake_bin / 'bash').symlink_to(shutil.which('bash'))
            (fake_bin / 'dirname').symlink_to(shutil.which('dirname'))
            result = subprocess.run(['bash', str(BOOTSTRAP)], env={'PATH': folder},
                                    capture_output=True, text=True)
            self.assertEqual(result.returncode, 2)
            self.assertIn('Missing tools:', result.stderr)
            self.assertIn('GitHub Actions', result.stderr)


if __name__ == '__main__':
    unittest.main()
