# Changelog

All notable changes to this project will be documented in this file.

## [2025.12-antigravity] - 2025-12-23
### Added
- **WSL Build Helper**: `build_wsl.sh` automates dependency checks and robustly handles git submodule updates.
- **Robustness**: Implemented auto-fallback to single-threaded git updates in `update_submodules.sh` to prevent WSL/NTFS locking errors.

### Fixed
- **Build System**: Fixed `scons.py` wrapper, converted CRLF line endings, and patched `SConscript` to use absolute paths.

## [Unreleased] - Antigravity Hydration

### Added

- **Simulation**: Added `SCAFFOLD/experiments/protocol_mock.cpp` to verify the "Protocol Factory" architecture and `Mover` instantiation without a full local build.
- **Documentation**: Updated `SCAFFOLD/NOTES.md` with architecture review.
