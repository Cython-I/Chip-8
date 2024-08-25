#define SDL_MAIN_HANDLED

#include "Chip8.h"
#include "SDL.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <windows.h>
#include <filesystem>
#include <sstream>
#include <codecvt>

void shutdownSDL(SDL_Window* window,SDL_Renderer* renderer) noexcept;
std::string getDemoRom(std::wstring demo = L"IBM.ch8");

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

	//Check if a romfile is specified, if not attempt to get a demo file

	std::string romFile{ argc > 1 ? argv[1] : getDemoRom()};

	if (!myChip.loadRom(romFile))
	{
		shutdownSDL(window, renderer);
		return 1;
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
	shutdownSDL(window, renderer);
	return 0;
}


static void shutdownSDL(SDL_Window* window, SDL_Renderer* renderer) noexcept
{
	if (renderer)
	{
		SDL_DestroyRenderer(renderer);
	}
	if (window)
	{
		SDL_DestroyWindow(window);
	}
	SDL_Quit();
}

static std::string getDemoRom(std::wstring demo)
{
	std::string stdDemoPathString{};
#if defined(_WIN32) || defined(_WIN64)
	wchar_t buffer[MAX_PATH];
	GetModuleFileNameW(NULL, buffer, MAX_PATH);
	std::wcout << buffer << '\n';
	std::filesystem::path exePath(buffer);
	std::wostringstream wos;
	auto pathToDemo = exePath.parent_path().parent_path().parent_path().parent_path();
	pathToDemo /= std::filesystem::path(L"Demo\\" + demo);
	std::wstring demoPathString = pathToDemo.wstring();
	if (!std::filesystem::exists(pathToDemo))
	{
		std::wcerr << "The specified demo: " << demoPathString << " was not found!" << '\n';
		return "N/A";
	}

	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;
	stdDemoPathString = converter.to_bytes(demoPathString);
#else 
	//implement code for linux
	stdDemoPathString = "Linux is not yet supported!";
#endif
	return stdDemoPathString;
}