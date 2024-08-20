// Chip8.h : Include file for standard system include files,
// or project specific include files.

#pragma once


#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

#include <bitset>

#define SCREENWIDTH 64
#define SCREENHEIGHT 32
#define STARTINDEX 512
#define FONTSTART 80

#define KILOBYTE 1024
#define MEMORYSIZE KILOBYTE*4

#define NIBBLE(instr) (instr & 0xf000)
#define X(instr) (instr & 0x0f00) >>8
#define Y(instr) (instr & 0x00f0) >> 4
#define N(instr) (instr & 0x000f) 
#define NN(instr) (instr & 0x0ff0) 
#define NNN(instr) (instr & 0x0fff) 
#define KK(instr) (instr & 0x00ff) 

class Chip8 {
public:
    void start();
    void loadRom(std::string rom);
    void setUp(SDL_Renderer*& render);
    void draw(int x, int y);
private:
    /*  Direct Access to up to 4kilobytes of RAM
    0x000 (0) -> 0x1FF (511) Reserved For Interpreter (Not to be used by programs)
    Chip-8 programs start at 0x200 (512) -> 0xFFF (4095)
    Some begin at 0x600 (1536), those starting in the latter are for ETI 660 computers
    */
    unsigned char memory[MEMORYSIZE];
    bool display[SCREENWIDTH][SCREENHEIGHT]{};//pixels total of 2048 or 64 * 32

    bool keyPressed;
    int scanCode;
    SDL_Renderer* Chiprenderer;

    unsigned short pc;//Program Counter 16-bit pointer
    std::stack<unsigned short> mystack;//Stack 16-bit
    unsigned short I; //Index Register 16-bit
    unsigned char V[16];//16 General Purpose Variable Registers V[0] - V[15] 8-bit
    unsigned char delay;//Sound Registers 8-bit
    unsigned char sound;//The sound timer is active whenever the sound timer register (ST) is non-zero.
    unsigned char keys[16];//Current state of keypad
};