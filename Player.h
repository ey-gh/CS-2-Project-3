#pragma once
#include <string>

class Arena;

class Player {
public:
	// Constructor
	Player(Arena*, int, int);

	// Accessors
	int row() const;
	int col() const;
	int age() const;
	bool isDead() const;

	// Mutators
	std::string takeComputerChosenTurn();
	void stand();
	void move(int);
	bool shoot(int);
	void setDead();

private:
	Arena* m_arena;
	int		m_row;
	int		m_col;
	int		m_age;
	bool	m_dead;
};