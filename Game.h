#pragma once

class Arena;

class Game {
public:
		// constructor
	Game(int, int, int);

		// destructor
	~Game();

		// mutators
	void play();

private:
	Arena* m_arena;
};