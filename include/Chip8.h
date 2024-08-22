#pragma once

#define SDL_MAIN_HANDLED

#include <iostream>
#include <fstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <array>
#include <vector>

#include "constants.h"  
#include "SDL.h"

class Chip8 {
public:
    Chip8(SDL_Renderer* const renderer) ;
    bool run();
    bool loadRom(const std::string& rom) ;
    void draw(int x, int y);

private:
    // Direct Access to up to 4 kilobytes of RAM
    // 0x000 (0) -> 0x1FF (511) Reserved For Interpreter (Not to be used by programs)
   
    std::array<uint8_t,memorySize> memory{};
    using DisplayMatrix = std::array<std::array<bool, screenHeight>, screenWidth>;//pixels total of 2048 or 64 * 32
    DisplayMatrix display{};

    bool keyPressed{ false };
    int scanCode{}; 
    SDL_Renderer* m_renderer{ nullptr };

    // Chip-8 programs start at 0x200 (512) -> 0xFFF (4095)
    uint16_t pc{ startIndex };
    std::stack<uint16_t> mystack;
    uint16_t I{};
    std::array<uint8_t,16> V{}; // 16-bit General Purpose Variable Registers V[0] - V[15]
    uint8_t delay{}; // Sound Register 8-bit
    uint8_t sound{}; // TODO: Activate whenever the sound timer register (ST) is non-zero.
    std::array<uint8_t,16> keys{}; // Current state of keypad
};
