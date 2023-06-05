#include "Game.h"
#include "globals.h"
#include "Arena.h"
#include "Player.h"

#include <iostream>

Game::Game(int rows, int cols, int nRobots) {
	if (nRobots > MAX_ROBOTS) {
		std::cout << "***** Trying to create Game with " << nRobots << " robots; only " << MAX_ROBOTS << " are allowed!\n";
		exit(1);
	}

	// create Arena
	m_arena = new Arena(rows, cols);

	// add player
	int rPlayer = 1 + rand() % rows;
	int cPlayer = 1 + rand() % cols;
	m_arena->addPlayer(rPlayer, cPlayer);

	// populate robots
	while (nRobots > 0) {
		int r = 1 + rand() % rows;
		int c = 1 + rand() % cols;

		// don't put a robot on top of a player
		if (r == rPlayer && c == cPlayer) {
			continue;
		}

		m_arena->addRobot(r, c);
		nRobots--;
	}
}

Game::~Game() {
	delete m_arena;
}

void Game::play() {
	Player* p = m_arena->player();
	if (p == nullptr) {
		m_arena->display("");
		return;
	}

	std::string msg = "";
	do {
		m_arena->display(msg);
		msg = "";
		std::cout << "\n";
		std::cout << "Move (u/d/l/r/su/sd/sl/sr/c//q): ";
		std::string action;
		std::getline(std::cin, action);
		if (action.size() == 0) {
			p->stand();
		}
		else {
			switch (action[0]) {
			default:
				std::cout << '\a' << '\n';
				continue;
			case 'q':
				return;
			case 'c':
				msg = p->takeComputerChosenTurn();
				break;
			case 'u':
			case 'd':
			case 'l':
			case 'r':
				p->move(decodeDirection(action[0]));
				break;
			case 's':
				if (action.size() < 2) {
					std::cout << '\a' << '\n';
					continue;
				}
				
				switch (action[1]) {
				default:
					std::cout << '\a' << '\n';
					continue;
				case 'u':
				case 'd':
				case 'l':
				case 'r':
					if (p->shoot(decodeDirection(action[1]))) {
						msg = "Hit!";
					}
					else {
						msg = "Missed!";
						break;
					}
				}

				break;
			}
		}
		m_arena->moveRobots();
	} while (!m_arena->player()->isDead() && m_arena->robotCount() > 0);
	
	m_arena->display(msg);
}