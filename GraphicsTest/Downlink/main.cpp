#include "SDL.h"
#include "Program.h"


Program *program = nullptr;

int main(int argc, char** argv)
{
	program = new Program();
	program->init("Downlink", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (program->checkRunning()) {
		program->handleEvent();
		program->render();

	}

	program->clean();

	return 0;
}