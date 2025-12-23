# Rosetta: Protein Structure Prediction

[![License](https://img.shields.io/badge/License-Rosetta-blue.svg)](https://www.rosettacommons.org/)
[![Website](https://img.shields.io/badge/Website-RosettaCommons-green.svg)](https://www.rosettacommons.org/)

**Rosetta** is the world's leading software suite for macromolecular modeling. It powers breakthroughs in protein design, docking, and structure prediction, enabling the creation of new therapeutics and materials.

---

> [!NOTE]
> **Antigravity Hydrated Fork**
> This repository is a verified hydration of the core Rosetta framework.

---

## 🚀 Quick Start

### 1. Build Recommendation (Windows)

> [!TIP]
> **Use WSL**: Rosetta's build system (`SCons`) is highly optimized for Linux environments. For the smoothest experience on Windows, we **strongly recommend** using **WSL (Ubuntu)**.

### 2. Full Build (Linux/WSL)

We provide a robust helper script that handles dependencies and common WSL git locking issues automatically:

```bash
# Run the robust build assistant
./build_wsl.sh
```

This script will:
1.  Check/Install system dependencies (`build-essential`, `zlib1g-dev`, `python3`).
2.  Update submodules (with auto-fallback to serial mode if WSL file locking occurs).
3.  Configure and run SCons for a Release build.

## 🧬 Features

- **Ab Initio Folding**: Predict structures from sequence alone.
- **Ligand Docking**: Model small molecule interactions.
- **Protein Design**: Engineer new proteins with specific functions.

## 🛠️ Development

### Contributing

Please see [CONTRIBUTING.md](CONTRIBUTING.md) for details on the Antigravity workflow.

### Architecture

Rosetta uses a **Factory Pattern** for its `Movers` (algorithms that alter a pose).

- **Core**: Basic chemical physics libraries.
- **Protocols**: High-level algorithms (Docking, Design).

## 📄 License

Rosetta is free for non-commercial use. Commercial use requires a license. See `LICENSE` for details.
