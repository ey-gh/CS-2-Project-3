#include "Player.h"
#include <iostream>

// constructor
Player::Player(Arena* ap, int r, int c) {
	m_arena = ap;
	m_row = r;
	m_col = c;
	m_age = 0;
	m_dead = false;
}

// get row
int Player::row() const {
	return m_row;
}

// get col
int Player::col() const {
	return m_col;
}

// get age
int Player::age() const {
	return m_age;
}

// check dead
bool Player::isDead() const {
	return m_dead;
}

// AI move
std::string Player::takeComputerChosenTurn() {
	std::cout << "not yet implemented\n";
	return "";
}

// stand
void Player::stand() {
	m_age++;
}

// move in some direction
void Player::move(int dir) {
	std::cout << "not yet implemented\n";
}

// shoot in some direction
bool Player::shoot(int dir) {
	std::cout << "not yet implemented\n";
	return false;
}

// kill player
void Player::setDead() {
	m_dead = true;
}