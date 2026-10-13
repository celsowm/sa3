# Reproducible SAT-R/agbcc compiler for the SA3 fork

Compiler pinned to SAT-R/agbcc `57a5b3e21157ffa5490deebfa4d6dcf0b3052d28`
(includes required updated libc/newlib). This is the **old original GBA compiler**;
Clang and modern GCC are not replacements for byte-identical matching.

## Option A — GitHub Actions, no local GCC setup

Visit **Actions → Build pinned agbcc toolchain → Run workflow** on `main`.
GitHub Actions may have to be enabled once in a fork using its Actions page.
The workflow builds `SAT-R/agbcc` on Ubuntu 22.04, compiles a sample C function
with the actual `agbcc` executable, assembles it with `arm-none-eabi-as`, and
publishes a downloadable `agbcc-linux-x86_64` compiler-only artifact. It
**does not download or upload the Sonic Advance 3 ROM**.

If Actions is disabled, no workflow can start via commits alone. Enable it
using GitHub's **Actions** page before relying on the result. A workflow YAML
file existing in a repository is not evidence that compilation ran.

On a Linux machine with `arm-none-eabi` binutils installed, place the archive
in the SA3 repository root and install it by running:

```sh
mkdir -p tools/agbcc
unzip agbcc-linux_x86_64.zip  # GitHub Actions downloads may rename the ZIP file
tar -C tools/agbcc -xzf agbcc-linux-x86_64.tar.gz
cat tools/agbcc/COMPILER_COMMIT
```

The artifact ZIP contains `agbcc-linux-x86_64.tar.gz`; the compiler binaries
target Linux x86-64. For macOS, use a compatible native compiler and ARM
binutils to build the original sources rather than running the Linux binaries.

## Option B — Build locally on Linux

```sh
sudo apt-get update
sudo apt-get install -y build-essential git python3 gcc-arm-none-eabi binutils-arm-none-eabi
bash scripts/bootstrap_agbcc.sh
```

The script checks prerequisites, clones `SAT-R/agbcc` alongside this repo,
checks out the pinned SHA, invokes `./build.sh`, and runs `./install.sh` to
place compiler binaries/headers/libraries into `tools/agbcc/`. It refuses
to overwrite arbitrary non-git files in the requested source folder.

## Verify exact European ROM locally

Never commit the reference ROM, copy it into public artifacts, or publish
its contents. Place the independently obtained Europe rev-0 image in the
repo root as `baserom_sa3.gba`. Verify its SHA-1:

```sh
printf '685af3a2dc0f1b3f8922e73ec42c1dc92e210e39  baserom_sa3.gba\n' | sha1sum -c -
make -j"$(nproc)" compare
sha1sum -c sa3.sha1
python3 scripts/progress.py text -m
```

The full ROM comparison is a separate step from installing the compiler.
For a secure GitHub runner-based comparison, configure the *existing* `CI`
workflow's `ENABLE_ROM_BUILD=true` variable and its protected `STORAGE_URL`,
`STORAGE_USERNAME`, `STORAGE_PASSWORD` secrets for an independently controlled
private ROM endpoint. Do not put ROM bytes in the repository, issues, PRs,
logs, or public artifact storage. The special agbcc-toolchain workflow does
not need any ROM secrets.

## Actual validation

A toolchain workflow does not prove GBA matching until the workflow run
succeeds. The `make compare` step additionally depends on an authorized
private European ROM and SA3 build assets. Do not increase progress just
because the compiler was successfully installed.
