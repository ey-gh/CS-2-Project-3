#pragma once
#include "globals.h"
#include <string>

class Player;
class Robot;

class Arena {
public:
	// constructor
	Arena(int, int);

	// destructor
	~Arena();

	// Accessors
	int rows() const;
	int cols() const;
	Player* player() const;
	int robotCount() const;
	int nRobotsAt(int, int) const;
	void display(std::string) const;
	bool addRobot(int, int);
	bool addPlayer(int, int);
	void damageRobotAt(int, int);
	bool moveRobots();

private:
	int m_rows;
	int m_cols;
	Player* m_player;
	Robot* m_robots[MAX_ROBOTS];
	int m_nRobots;
};