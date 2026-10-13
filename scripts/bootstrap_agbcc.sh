#!/usr/bin/env bash
# Build and install the exact SAT-R/agbcc toolchain used by this SA3 fork.
# This script DOES NOT download, read, or upload any ROM.
set -Eeuo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
AGBCC_SHA='57a5b3e21157ffa5490deebfa4d6dcf0b3052d28'
AGBCC_SOURCE_DIR="${AGBCC_SOURCE_DIR:-$(dirname "$REPO_ROOT")/agbcc-src}"

required=(git make gcc g++ python3 arm-none-eabi-as arm-none-eabi-ar arm-none-eabi-ld arm-none-eabi-cpp arm-none-eabi-objcopy)
missing=()
for command_name in "${required[@]}"; do
    command -v "$command_name" >/dev/null 2>&1 || missing+=("$command_name")
done
if (("${#missing[@]}")); then
    printf 'Missing tools: %s\n' "${missing[*]}" >&2
    printf '%s\n' 'Ubuntu/Debian: sudo apt-get update && sudo apt-get install -y build-essential git python3 gcc-arm-none-eabi binutils-arm-none-eabi' >&2
    printf '%s\n' 'Use the GitHub Actions agbcc-toolchain workflow if your local environment blocks package installs/network.' >&2
    exit 2
fi

AGBCC_SOURCE_DIR="$(python3 -c 'import os,sys;print(os.path.abspath(sys.argv[1]))' "$AGBCC_SOURCE_DIR")"
if [[ ! -d "$AGBCC_SOURCE_DIR/.git" ]]; then
    if [[ -e "$AGBCC_SOURCE_DIR" ]]; then
        printf 'Refusing non-git source directory: %s\n' "$AGBCC_SOURCE_DIR" >&2
        exit 2
    fi
    git clone https://github.com/SAT-R/agbcc.git "$AGBCC_SOURCE_DIR"
fi

git -C "$AGBCC_SOURCE_DIR" fetch --depth=1 origin "$AGBCC_SHA"
git -C "$AGBCC_SOURCE_DIR" checkout --detach "$AGBCC_SHA"
actual="$(git -C "$AGBCC_SOURCE_DIR" rev-parse HEAD)"
if [[ "$actual" != "$AGBCC_SHA" ]]; then
    printf 'Compiler source commit mismatch: %s\n' "$actual" >&2
    exit 2
fi

install_dir="$REPO_ROOT/tools/agbcc"
if [[ -f "$install_dir/COMPILER_COMMIT" ]] && [[ "$(cat "$install_dir/COMPILER_COMMIT")" == "$AGBCC_SHA" ]] &&
   [[ -x "$install_dir/bin/agbcc" ]] && [[ -x "$install_dir/bin/old_agbcc" ]] &&
   [[ -x "$install_dir/bin/agbcc_arm" ]] && [[ -s "$install_dir/lib/libc.a" ]] &&
   [[ -s "$install_dir/lib/libgcc.a" ]]; then
    printf 'SAT-R/agbcc already installed at %s (%s)\n' "$install_dir" "$AGBCC_SHA"
    exit 0
fi

(
    cd "$AGBCC_SOURCE_DIR"
    ./build.sh
    ./install.sh "$REPO_ROOT"
)
for path in bin/agbcc bin/old_agbcc bin/agbcc_arm lib/libc.a lib/libgcc.a; do
    test -s "$install_dir/$path" || { printf 'Install missing %s\n' "$path" >&2; exit 3; }
done
printf '%s\n' "$AGBCC_SHA" > "$install_dir/COMPILER_COMMIT"
printf 'SAT-R/agbcc compiled and installed at %s\n' "$install_dir"
printf 'Compiler source commit: %s\n' "$AGBCC_SHA"
