#include "stdafx.h"
#include "MazeAlgorithm.h"
#include "Maze.h"
#include <iostream>
#include <vector>
#include <queue>

#define STEP_COST 1
#define TURN_COST 2

using namespace std;

const static vector<directions> dirIterate = { dirNorth, dirSouth, dirEast, dirWest };


MazeAlgorithm::MazeAlgorithm(int size, point finish) : maze(size), size(size), finish(finish)
{
}


MazeAlgorithm::~MazeAlgorithm()
{
}

void MazeAlgorithm::mazeSolve(bool startToFinish) {
	solvingInit(startToFinish);

	while (!pointsToExpand.empty()) {
		position currentPosition = pointsToExpand.front();
		pointsToExpand.pop();
		int walls = maze.getWalls(currentPosition.coordinates);
		directions lookingDir;
		for (unsigned int i = 0; i < dirIterate.size(); i++) {
			lookingDir = dirIterate[i];
			if ((walls & lookingDir) == 0) {
				updateCost(currentPosition, lookingDir);
			}
		}
	}
}

void MazeAlgorithm::mazeSolve(void) {
	mazeSolve(true);
}

void MazeAlgorithm::updateCost(position currentPosition, directions nextDirection) {
	Walker walker(size, currentPosition.coordinates);
	if (walker.move(nextDirection)) {
		int turnCost = (currentPosition.looking_direction == nextDirection ? 0 : TURN_COST);
		int calculatedCost = maze.getCost(currentPosition.coordinates) + STEP_COST + turnCost;
		int nextCost = maze.getCost(walker.getPoint());
		if ((nextCost == -1) || (nextCost >= calculatedCost)) {
			maze.setCost(walker.getPoint(), calculatedCost);
			pointsToExpand.push({ walker.getPoint(), nextDirection });
			update_count++;
		}
	}
}



void MazeAlgorithm::solvingInit(bool startToFinish) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			maze.setCost({ i, j }, -1);
		}
	}
	queue<position>().swap(pointsToExpand); // clearing queue

	if (startToFinish) {
		maze.setCost({ finish.x - 1,  finish.y - 1 }, 0);
		maze.setCost({ finish.x,  finish.y - 1 }, 0);
		maze.setCost({ finish.x - 1,  finish.y }, 0);
		maze.setCost(finish, 0);

		for (unsigned int i = 0; i < dirIterate.size(); i++) {
			pointsToExpand.push({ { finish.x - 1,  finish.y - 1 }, dirIterate[i] });
			pointsToExpand.push({ { finish.x,  finish.y - 1 }, dirIterate[i] });
			pointsToExpand.push({ { finish.x - 1,  finish.y }, dirIterate[i] });
			pointsToExpand.push({ finish, dirIterate[i] });
		}
	}
	else {
		maze.setCost({ 0,  0 }, 0);
		pointsToExpand.push({ { 0,  0 }, dirNorth });
		pointsToExpand.push({ { 0,  0 }, dirEast });
	}

}

void MazeAlgorithm::mazeDiscover(void) {
	bool noNewCells = false;
	while (true) {
		if (mazeCross(true))
			break;
		if (mazeCross(false))
			break;
	}
	//maze.printMaze();
}

bool MazeAlgorithm::mazeCross(bool startToFinish) {
	bool noNewCells = true;
	mazeSolve(startToFinish);
	while (maze.getCost(maze.getCurrentPoint()) != 0) {
		int walls = maze.getWalls(maze.getCurrentPoint());
		for (unsigned int i = 0; i < dirIterate.size(); i++)
			if ((walls & dirIterate[i]) != 0)
				maze.addWall(maze.getCurrentPoint(), dirIterate[i]);
		position newPos = findNextStep(maze.getCurrentPosition());
		bool firstTime = !maze.isCellVisited(newPos.coordinates);
		maze.move(newPos.looking_direction);
		if (firstTime) {
			mazeSolve(startToFinish);
			noNewCells = false;
		}
	}
	maze.printMaze();
	return noNewCells;
}

position MazeAlgorithm::findNextStep(position currentPosition) {
	directions dir;
	int min = 0x7FFFFFFF;
	position nextPos;
	for (unsigned int i = 0; i < dirIterate.size(); i++) {
		dir = dirIterate[i];
		Walker walker(size, currentPosition.coordinates);
		if (((maze.getWalls(currentPosition.coordinates) & dir) == 0)
			&& walker.move(dir)
			&& (maze.getCost(walker.getPoint()) < min)) {
			nextPos.looking_direction = dir;
			min = maze.getCost(walker.getPoint());
			nextPos.coordinates = walker.getPoint();
		}
	}
	return nextPos;
}
