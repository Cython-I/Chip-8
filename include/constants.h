#pragma once

// Screen dimensions
constexpr int screenWidth = 64;
constexpr int screenHeight = 32;

// Memory and font settings
constexpr int startIndex = 0x200;
constexpr int fontStart = 0x50;
constexpr int kilobyte = 1024;
constexpr int memorySize = kilobyte * 4;

// Helper functions
constexpr unsigned short instructionNibble(unsigned short instr) { return (instr & 0xf000); }
constexpr unsigned short instructionX(unsigned short instr) { return (instr & 0x0f00) >> 8; }
constexpr unsigned short instructionY(unsigned short instr) { return (instr & 0x00f0) >> 4; }
constexpr unsigned short instructionN(unsigned short instr) { return (instr & 0x000f); }
constexpr unsigned short instructionNN(unsigned short instr) { return (instr & 0x00ff); }
constexpr unsigned short instructionNNN(unsigned short instr) { return (instr & 0x0fff); }
constexpr unsigned short instructionKK(unsigned short instr) { return (instr & 0x00ff); }
