
#define SDL_MAIN_HANDLED

#include "Chip8.h"
#include "SDL.h"
#include <chrono>
#include <thread>

int main(int argc, char* argv[]) 
{
	
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(screenWidth * 4, screenWidth * 4, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 4, 4);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	Chip8 myChip(renderer);
	std::string romFile{ "4-flags.ch8" };

	if (argc > 1) 
	{
		romFile = argv[1];
	}


	auto shutDown = [&](int exitCode) 
	{
		SDL_Delay(1000);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return exitCode;
	};

	if (!myChip.loadRom(romFile))
	{
		return shutDown(1);
	}

	auto now = std::chrono::steady_clock::now();
	auto prevFrame = std::chrono::steady_clock::now();

	
	SDL_Event evt;
	bool programRunning = true;
	//MAIN LOOP
	while (programRunning)
	{
		while (SDL_PollEvent(&evt))
		{
			switch (evt.type)
			{
				case SDL_QUIT:  
					programRunning = false; 
					break;
			}
		}
	
		now = std::chrono::steady_clock::now();
	
		if (!myChip.run())
		{
			programRunning = false;
		}
	
		std::chrono::duration<double, std::milli> delta = now - prevFrame;
	
		prevFrame = now;
		std::chrono::duration<double, std::milli> delta_ms(700.0 - delta.count());
		auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
		std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));

	}
	return shutDown(0);
}
