#include "Robot.h"
#include <iostream>
// constructor
Robot::Robot(Arena* ap, int r, int c) {
	m_arena = ap;
	m_row = r;
	m_col = c;
	m_hp = 2;
}

// return robot row, taking into consideration zero-based indexing
int Robot::row() const {
	return m_row;
}

// return robot column
int Robot::col() const {
	return m_col;
}

// move robot
void Robot::move() {
	std::cout << "not yet implemented\n";
}

// does robot live after taking damage
bool Robot::takeDamageAndLive() {
	--m_hp;
	return m_hp != 0;
}