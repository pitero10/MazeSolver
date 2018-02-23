#pragma once
#include <queue>
#include "Walker.h"

typedef enum {

} mazeDetails;

class Maze {
	int ** mazeGrid;
	int ** mazeWeights;
	int size;
	point finish;
	Walker mouse;
	void printWall(int x, int y, int mask, int len);
	int getCodedWalls(int x, int y); //TODO only for testing
public:
	Maze(int size);
	~Maze();
	void testData(void); //TODO only for testing
	void printMaze(void);
	void addWall(point p, directions dir);
	void addWalls(point p, int dirs);
	int getWalls(point p);
	int getCost(point point);
	void setCost(point point, int cost);
	point getCurrentPoint(void);
	position getCurrentPosition(void);
	void visitCell(point point);
	bool isCellVisited(point point);
	bool move(directions direction);
};

