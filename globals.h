#pragma once

const int MAX_ROWS = 20;        // max number of rows in the arena
const int MAX_COLS = 40;        // max number of columns in the arena
const int MAX_ROBOTS = 130;        // max number of robots allowed on field
const int MAX_SHOT_LEN = 5;        // max distance a bullet can travel

// directional input
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

int decodeDirection(char);
void clearScreen();