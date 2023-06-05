#pragma once

class Arena;

class Robot {
public:
	// Constructor
	Robot(Arena*, int, int);

	// Accessors
	int row() const;
	int col() const;

	// Mutators
	void move();
	bool takeDamageAndLive();

private:
	Arena*	m_arena;
	int		m_row;
	int		m_col;
	int		m_hp;
};