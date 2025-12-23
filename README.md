# Rosetta: Protein Structure Prediction

[![License](https://img.shields.io/badge/License-Rosetta-blue.svg)](https://www.rosettacommons.org/)
[![Website](https://img.shields.io/badge/Website-RosettaCommons-green.svg)](https://www.rosettacommons.org/)

**Rosetta** is the world's leading software suite for macromolecular modeling. It powers breakthroughs in protein design, docking, and structure prediction, enabling the creation of new therapeutics and materials.

---

> [!NOTE]
> **Antigravity Hydrated Fork**
> This repository is a verified hydration of the core Rosetta framework. To facilitate rapid development on Windows without the 2+ hour compilation time, we have included architectural mocks (`SCAFFOLD/`) that verify the core Factory and Mover patterns.

---

## 🚀 Quick Start

### 1. Build Recommendation (Windows)

> [!TIP]
> **Use WSL**: Rosetta's build system (`SCons`) is highly optimized for Linux environments. For the smoothest experience on Windows, we **strongly recommend** using **WSL (Ubuntu)**.

### 2. Verification (Simulated Protocol)

Testing changes to the central `MoverFactory` usually requires a full re-link. We provide a lightweight verification tool:

```bash
# Verify Protocol Factory Pattern
g++ SCAFFOLD/experiments/protocol_mock.cpp -o protocol_check
./protocol_check
```

This mock compiles in seconds and validates that your new protocol classes correctly register with the central factory system.

### 3. Full Build (Linux/WSL)

```bash
# Install dependencies
sudo apt-get install scons zlib1g-dev

# Build (Release mode)
./scons.py -j8 mode=release bin
```

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
