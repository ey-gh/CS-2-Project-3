#include "Arena.h"
#include "Robot.h"
#include "Player.h"
#include "globals.h"
#include <iostream>

// constructor
Arena::Arena(int nRows, int nCols) {
	m_rows = nRows;
	m_cols = nCols;
	m_player = nullptr;
	for (int i = 0; i < MAX_ROBOTS; i++) {
		m_robots[i] = nullptr;
	}
	m_nRobots = 0;
}

// destructor
Arena::~Arena() {
	delete m_player;
	for (int i = 0; i < MAX_ROBOTS; i++) {
		if (m_robots[i] != nullptr) {
			delete m_robots[i];
		}
	}
}

// get rows
int Arena::rows() const {
	return m_rows;
}

// get columns
int Arena::cols() const {
	return m_cols;
}

// get player
Player* Arena::player() const {
	return m_player;
}

// get robot count in arena
int Arena::robotCount() const {
	return m_nRobots;
}

// get robot count in position
int Arena::nRobotsAt(int r, int c) const {
	int count = 0;
	for (int i = 0; i < MAX_ROBOTS; i++) {
		// 0-based so -> m_robot[i]->row() - 1 ???
		if (m_robots[i] != nullptr && m_robots[i]->row() - 1 == r && m_robots[i]->col() - 1 == c) {
			count++;
		}
	}

	return count;
}

// show board
void Arena::display(std::string msg) const {
	char grid[MAX_ROWS][MAX_COLS];
	int r, c;

	for (r = 0; r < rows(); r++) {
		for (c = 0; c < cols(); c++) {
			grid[r][c] = '.';
		}
	}

	for (r = 0; r < rows(); r++) {
		for (c = 0; c < cols(); c++) {
			int count = 0;
			for (int i = 0; i < MAX_ROBOTS; i++) {
				if (m_robots[i] != nullptr && m_robots[i]->row() - 1 == r && m_robots[i]->col() - 1 == c) {
					count++;
				}
			}
			if (count == 1) {
				grid[r][c] = 'R';
			}
			else if (count > 1 && count < 9) {
				std::string s = std::to_string(count);
				grid[r][c] = s[0];
			}
			else {
				std::string s = std::to_string(count);
				grid[r][c] = s[0];
			}
		}
	}

	if (m_player != nullptr) {
		char& gridChar = grid[m_player->row() - 1][m_player->col() - 1];
		if (gridChar == '.') {
			gridChar = '@';
		}
		else {
			gridChar = '*';
		}
	}

	clearScreen();

	for (r = 0; r < rows(); r++) {
		for (c = 0; c < cols(); c++) {
			std::cout << grid[r][c];
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	std::cout << '\n';
	if (msg != "") {
		std::cout << msg << '\n';
	}
	std::cout << "There are " << robotCount() << " robots remaining." << '\n';
	if (m_player == nullptr) {
		std::cout << "There is no player." << '\n';
	}
	else {
		if (m_player->age() > 0) {
			std::cout << "The player has lasted " << m_player->age() << " steps." << '\n';
		}
		if (m_player->isDead()) {
			std::cout << "The player is dead." << '\n';
		}
	}
}

// add robot to arena
bool Arena::addRobot(int r, int c) {
	if (m_nRobots == MAX_ROBOTS) {
		return false;
	}

	for (int i = 0; i < MAX_ROBOTS; i++) {
		if (m_robots[i] == nullptr) {
			m_robots[i] = new Robot(this, r, c);
			return true;
		}
	}

	return false;
}

// add player to arena
bool Arena::addPlayer(int r, int c) {
	if (m_player != nullptr) {
		return false;
	}

	m_player = new Player(this, r, c);
	return true;
}

// damage robot
void Arena::damageRobotAt(int r, int c) {
	if (nRobotsAt(r, c) > 0) {
		for (int i = 0; i < MAX_ROBOTS; i++) {
			if (m_robots[i] != nullptr && m_robots[i]->row() - 1 == r && m_robots[i]->col() - 1 == c) {
				if (!m_robots[i]->takeDamageAndLive()) {
					delete m_robots[i];
					m_robots[i] = nullptr;
					m_nRobots--;
				}

				break;
			}
		}
	}
}

// move robots
bool Arena::moveRobots() {
	for (int i = 0; i < MAX_ROBOTS; i++) {
		if (m_robots[i] != nullptr) {
			m_robots[i]->move();
			if (m_robots[i]->row() == m_player->row() && m_robots[i]->col() == m_player->col()) {
				m_player->setDead();
			}
		}
	}

	return !m_player->isDead();
}