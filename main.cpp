// main.cpp

#include "Game.h"
#include <ctime>
#include <cstdlib>





int main() {
	srand(static_cast<unsigned int>(time(0)));

		// create a game
	Game g(3, 3, 0);

		// play game
	g.play();
}