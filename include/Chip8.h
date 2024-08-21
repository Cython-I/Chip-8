#pragma once

#define SDL_MAIN_HANDLED

#include <iostream>
#include <fstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <array>
#include <vector>
#include <string_view>

#include "constants.h"  
#include "SDL.h"

class Chip8 {
public:
    Chip8(SDL_Renderer* const renderer) ;
    void start();
    bool loadRom(const std::string& rom) ;
    void draw(int x, int y);

private:
    // Direct Access to up to 4 kilobytes of RAM
    // 0x000 (0) -> 0x1FF (511) Reserved For Interpreter (Not to be used by programs)
    // Chip-8 programs start at 0x200 (512) -> 0xFFF (4095)
    // Some begin at 0x600 (1536), those starting in the latter are for ETI 660 computers

    unsigned char memory[memorySize]{}; 
    bool display[screenWidth][screenHeight]{}; //pixels total of 2048 or 64 * 32

    bool keyPressed = false; 
    int scanCode{}; 
    SDL_Renderer* m_renderer = nullptr; 

    unsigned short pc = startIndex; // Program Counter starts at 0x200
    std::stack<unsigned short> mystack; // Stack  16-bit
    unsigned short I{}; // Index Register 16-bit
    unsigned char V[16]{}; // 16-bit General Purpose Variable Registers V[0] - V[15]
    unsigned char delay{}; // Sound Register 8-bit
    unsigned char sound{}; // TODO: Activate whenever the sound timer register (ST) is non-zero.
    unsigned char keys[16]{}; // Current state of keypad
};
