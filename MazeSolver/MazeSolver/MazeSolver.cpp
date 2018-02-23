// MazeSolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MazeAlgorithm.h"
#include <iostream>

#define MAZE_SIZE  16
#define MAZE_FINISH_X  (MAZE_SIZE / 2)
#define MAZE_FINISH_Y  (MAZE_SIZE / 2)


int main()
{
	MazeAlgorithm mazeAlg(MAZE_SIZE, { MAZE_FINISH_X, MAZE_FINISH_Y });
	mazeAlg.mazeDiscover();
	mazeAlg.mazeSolve();
	int a;
	std::cin >> a;
	return 0;
}

