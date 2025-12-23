# Contributing to Rosetta

Join the community solving the hardest problems in protein science.

## 🚀 Getting Started

### 1. The Build Challenge

Rosetta is a massive C++ codebase. Compiling it fully can take hours.

**Build Helper (WSL/Linux)**:
Use our robust build script to handle dependencies and git locking issues automatically:
```bash
./build_wsl.sh
```

**Alternative**: Use our **Antigravity Protocol Mock** for architectural development without a full build.

### 2. Antigravity Verification

- **Tool**: `SCAFFOLD/experiments/protocol_mock.cpp`
- **Purpose**: Verify that your new Mover class follows the Factory registration pattern correctly *before* you try to integrate it into the massive main build.
- **Run**: `g++ SCAFFOLD/experiments/protocol_mock.cpp -o protocol_check && ./protocol_check`

### 3. Submission Process

1. **Fork** the repository.
2. Create a **feature branch**.
3. **Commit** your changes.
4. **Push** to your fork and submit a **Pull Request**.

### 4. Code Style

- Rosetta has strict coding conventions.
- See the [Wiki](https://www.rosettacommons.org/docs/latest/development_documentation/Development-Documentation) for details.

## 🧪 Testing

- **Unit Tests**: Run `scons cat=test` (requires Linux/WSL).
- **Integration**: Use the Integration Test server (for core developers).

## 🤝 Community

- [RosettaCommons](https://www.rosettacommons.org/)
- [Forums](https://www.rosettacommons.org/forum)

Thank you for contributing to the future of biotech!
