#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include "Chip8.h"


using namespace std::chrono;

int main(int argc, char* argv[]) {
	Chip8 myChip;

	//RENDERING
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_CreateWindowAndRenderer(SCREENWIDTH * 4, SCREENHEIGHT * 4, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 4, 4);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	myChip.setUp(renderer);

	//ROM SETUP
	std::string romFile{ "test_opcode.ch8" };

	if (argc > 1) {
		romFile = argv[1];
	}
	 
	myChip.loadRom(romFile);

	auto now = steady_clock::now();
	auto prevFrame = steady_clock::now();

	//MAIN LOOP
	int count{};
	SDL_Event evt;
	bool programRunning = true;

	while (programRunning) {
		while (SDL_PollEvent(&evt))
		{
			switch (evt.type)
			{
			case SDL_QUIT:  programRunning = false; break;
			}
		}

		now = steady_clock::now();

		myChip.start();

		duration<double, std::milli> delta = now - prevFrame;

		prevFrame = now;
		std::chrono::duration<double, std::milli> delta_ms(700.0 - delta.count());
		auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
		std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));

		count++;
	}
	SDL_Delay(1000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}