#include "Game.h"
#include <ctime>

#ifdef _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <cstdlib>
	#include <crtdbg.h>
#endif

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

	Game game{};
	game.run();

	// Check for memory leaks TODO why gibt es leaks
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

    return 0;
}