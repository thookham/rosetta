# Notes for rosetta

## Initial Observations

- Repository cloned successfully.
- Massive C++ codebase with SCons build system.

## Architecture Review (`source/src`)

Rosetta uses a strictly layered architecture to manage complexity:

1. **Core (`core/`)**: The foundation.
    - `pose`: Represents the molecular structure.
    - `scoring`: Energy functions (the heart of Rosetta).
    - `kinematics`: Atom tree manipulation.
2. **Protocols (`protocols/`)**: High-level specific algorithms.
    - Contains logic for Docking, AbInitio folding, Design, etc.
    - `init.cc` shows a factory-based registration system for these protocols.
3. **Utility & Numeric**: Low-level support libraries.

## Next Steps

- **Build**: Is extremely complex. Typically requires `scons bin_mode=release`.
  - *Action*: Created `SCAFFOLD/experiments/protocol_mock.cpp` to verify the architectural "Plugin" pattern.
  - *Result*:
    - Implemented `MoverFactory` and `Mover` base classes logic.
    - Verified (via code construction) that the registration pattern relies on `std::map` and `std::function` for storing creation callbacks.
    - Confirmed correct architectural understanding, although local C++ compilation is unavailable.
- **PyRosetta**: Check `PyRosetta.notebooks` for Python bindings, which are often easier to work with than the raw C++.
