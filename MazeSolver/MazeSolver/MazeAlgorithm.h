#pragma once

#include "Maze.h"
#include "Walker.h"

class MazeAlgorithm
{
	int size;
	Maze maze;
	point finish;
	std::queue<position> pointsToExpand;
	void updateCost(position currentPosition, directions nextDirection);
	void solvingInit(bool startToFinish);
	int update_count; //TODO Delete
	position findNextStep(position currentPosition);
	void mazeSolve(bool startToFinish);
	bool mazeCross(bool startToFinish);

public:
	MazeAlgorithm(int size, point finish);
	~MazeAlgorithm();
	void mazeSolve(void);
	void mazeDiscover(void);
};

