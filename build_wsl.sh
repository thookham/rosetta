#!/bin/bash
set -e

# Rosetta WSL Build Helper
# Automated dependency check and build invocation.

echo "=================================="
echo "   Rosetta WSL Build Assistant    "
echo "=================================="

# 1. Dependency Check
echo "[+] Checking system dependencies..."

deps_needed=0
for package in build-essential zlib1g-dev python3; do
    if ! dpkg -s $package >/dev/null 2>&1; then
        echo "    -> Missing: $package"
        deps_needed=1
    fi
done

if [ $deps_needed -eq 1 ]; then
    echo "[!] Missing dependencies detected. Installing..."
    sudo apt-get update
    sudo apt-get install -y build-essential zlib1g-dev python3
else
    echo "    -> All system dependencies met."
fi

# 2. Build Configuration
CORES=$(nproc)
echo "[+] Detected $CORES CPU cores."

# Ensure we are in the right place
if [ ! -f "source/SConstruct" ]; then
    echo "[!] Error: source/SConstruct not found."
    echo "    Please run this script from the root of the Rosetta repository."
    exit 1
fi

cd source

# 3. Invoke SCons
echo "[+] Starting SCons build (Release Mode)..."
echo "    CMD: ./scons.py -j$CORES mode=release bin"
echo "    (This may take 30-60 minutes on the first run)"

# Use python3 explicit invocation for scons.py wrapper
python3 scons.py -j$CORES mode=release bin

echo ""
echo "[+] Build Complete."
echo "    Binaries are located in: source/bin/"
