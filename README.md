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
#### NOTE: Only tested with Visual Studio 2022!
### Building the Project

1. **Clone the Repository**

   First, clone the repository to your local machine:

   ```bash
   git clone https://github.com/Cython-I/Chip8.git
   cd Chip8
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
   
### Running the Emulator
To run the emulator, you need to provide the path to a .c8 file as a command-line argument. For example:

```bash
build/../Chip8.exe path/to/yourfile.c8
```
Replace path/to/yourfile.c8 with the path to your Chip-8 ROM file. 

I have provided two roms as test in the Demo folder. These are from user [Timendus](https://github.com/Timendus) and I have no credit in their creation. You can however test with additional roms from
Timendus from his chip8 testing repo here: [chip8-test-suite repo](https://github.com/Timendus/chip8-test-suite?tab=readme-ov-file) 

### Sources for Roms
- Both roms are credited to [Timendus](https://github.com/Timendus) I have only worked on the emulator itself NOT the two included roms
* [IBM](https://github.com/Timendus/chip8-test-suite?tab=readme-ov-file#ibm-logo) 
* [Corax+ opcode test](https://github.com/Timendus/chip8-test-suite?tab=readme-ov-file#corax-opcode-test)


### License
This project is licensed under the MIT License.
