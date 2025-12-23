# Rosetta on WSL: Technical Guide

This fork of Rosetta has been optimized for the **Windows Subsystem for Linux (WSL)** environment.

## The Challenge

Running massive C++ builds like Rosetta on WSL (specifically on `/mnt/c` mounts) presents unique challenges:

1.  **File Locking**: The NTFS file system does not handle parallel git operations (`git submodule update --jobs N`) gracefully when accessed via WSL. This often leads to `index.lock` collisions and crashed updates.
2.  **Path Length**: Deeply nested source trees in Rosetta can exceed the Windows `MAX_PATH` (260 characters) limit, causing `checkout` failures.
3.  **Line Endings**: Shell scripts checked out on Windows often acquire CRLF line endings, which break execution in the Linux shell (`/bin/bash^M: bad interpreter`).

## The Antigravity Solution

We have introduced a **"Self-Healing" Build System** to address these issues transparently.

### 1. The Build Assistant (`build_wsl.sh`)
This is your primary entry point. It automates:
- **Dependency Checks**: Verifies `build-essential`, `zlib1g-dev`, etc.
- **Environment Setup**: Configures SCons for the WSL environment.

### 2. Robust Git Updates (`source/update_submodules.sh`)
We rewrote the submodule update logic to be **Adaptive**:
- **Attempt 1 (Optimistic)**: Tries a fast, parallel update (`--opts`).
- **Fallback (Robust)**: If locking errors are detected, it automatically switches to **Single-Threaded Mode** (`--jobs 1`).
- **Result**: You get the fastest possible build that your filesystem can support, without manual intervention.

### 3. SCons Wrappers
- **`source/scons.py`**: Replaced the standard wrapper with a subprocess-based launcher that preserves environment variables and correct path resolution (`__file__`).
- **`source/SConscript`**: Patched to use **absolute paths**, fixing SCons execution failures when the working directory changes during the build graph evaluation.

## Troubleshooting

If you still encounter issues:

1.  **Enable Long Paths**:
    ```bash
    git config --global core.longpaths true
    ```
2.  **Clean Git Locks**:
    ```bash
    find . -name "index.lock" -delete
    ```
3.  **Manual Build**:
    ```bash
    ./build_wsl.sh
    ```
