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
constexpr uint16_t instructionNibble(uint16_t instr) { return (instr & 0xf000); }
constexpr uint16_t instructionX(uint16_t instr) { return (instr & 0x0f00) >> 8; }
constexpr uint16_t instructionY(uint16_t instr) { return (instr & 0x00f0) >> 4; }
constexpr uint16_t instructionN(uint16_t instr) { return (instr & 0x000f); }
constexpr uint16_t instructionNN(uint16_t instr) { return (instr & 0x00ff); }
constexpr uint16_t instructionNNN(uint16_t instr) { return (instr & 0x0fff); }
constexpr uint16_t instructionKK(uint16_t instr) { return (instr & 0x00ff); }
