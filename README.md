# Chip-8 Emulator

This is a simple Chip-8 emulator written in C++. It emulates the Chip-8 virtual machine, allowing you to run and debug Chip-8 programs.

## Features

- Emulation of the Chip-8 instruction set
- Support for basic graphics and input
- Ability to load and run Chip-8 ROMs

## Getting Started

To get started with the Chip-8 emulator, follow these steps to build and run the project:

### Prerequisites

- CMake (version 3.x or later)
- A C++ compiler (e.g., GCC, Clang, MSVC)
- [Optional] SDL2 library (The VC library is included, so no adjustments needed if working with Visual Studio)

### Building the Project

1. **Clone the Repository**

   First, clone the repository to your local machine:

   ```bash
   git clone https://github.com/yourusername/chip8.git
   cd chip8
   ```
2. **Generate Build Files**
   Create a build directory and generate the build system files with CMake:
   ```bash
   cmake -S . -B build
   ```
4. **Build The Project**
   Use CMake to build the project (can specify release build with '--config Release' at the end this command):
   ```bash
   cmake --build build
   ```
5. **Locatate exe**
   Should be located in the build folder generated, Debug or Release.

##License
This project is licensed under the MIT License.
