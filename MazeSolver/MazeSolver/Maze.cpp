#include "stdafx.h"
#include "Maze.h"
#include <iostream>
#include <vector>

using namespace std;

const static vector<directions> dirIterate = { dirNorth, dirSouth, dirEast, dirWest };

enum {
	cellVisited = 0x10
};

Maze::Maze(int size) : mouse(size, { 0, 0 }, dirNorth), size(size) {
	mazeGrid = new int*[size];
	mazeWeights = new int*[size];
	for (int i = 0; i < size; i++) {
		mazeGrid[i] = new int[size];
		mazeWeights[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mazeGrid[i][j] = 0;
			mazeWeights[i][j] = -1;
		}
	}
	testData();
	addWalls(getCurrentPoint(), getCodedWalls(getCurrentPoint().x, getCurrentPoint().y));
}

Maze::~Maze() {
	for (int i = 0; i < size; i++) {
		delete[] mazeGrid[i];
		delete[] mazeWeights[i];
	}
	delete[] mazeGrid;
	delete[] mazeWeights;

}

void Maze::addWall(point p, directions dir) {
	mazeGrid[p.x][p.y] |= dir;
	Walker walker(size, p);
	if (walker.move(dir))
		switch (dir) {
		case dirNorth:
			mazeGrid[p.x][p.y + 1] |= dirSouth;
			break;
		case dirSouth:
			mazeGrid[p.x][p.y - 1] |= dirNorth;
			break;
		case dirEast:
			mazeGrid[p.x + 1][p.y] |= dirWest;
			break;
		case dirWest:
			mazeGrid[p.x - 1][p.y] |= dirEast;
			break;
		}
}

void Maze::addWalls(point p, int dirs) {
	for (unsigned int i = 0; i < dirIterate.size(); i++)
		if ((dirs & dirIterate[i]) != 0)
			addWall(p, dirIterate[i]);
}

int Maze::getWalls(point p) {
	return (mazeGrid[p.x][p.y] & dirMask);
}

int Maze::getCost(point point) {
	return mazeWeights[point.x][point.y];
}

void Maze::setCost(point point, int cost) {
	mazeWeights[point.x][point.y] = cost;
}

point Maze::getCurrentPoint(void) {
	return mouse.getPoint();
}

position Maze::getCurrentPosition(void) {
	return mouse.getPosition();
}

void Maze::visitCell(point point) {
	mazeGrid[point.x][point.y] |= cellVisited;
}

bool Maze::isCellVisited(point point) {
	return (mazeGrid[point.x][point.y] & cellVisited) == cellVisited;
}

bool Maze::move(directions direction) {
	if (((getWalls(mouse.getPoint()) & direction) == 0)
		&& mouse.move(direction)) {
		visitCell(mouse.getPoint());
		cout << mouse.getPoint().x << "  " << mouse.getPoint().y << '\n';
		int walls = getCodedWalls(mouse.getPoint().x, mouse.getPoint().y);
		addWalls(mouse.getPoint(), walls);
		return true;
	}
	return false;

}


void Maze::printMaze(void) {
	for (int i = size - 1; i >= 0; i--) {
		std::cout << "   ";
		for (int j = 0; j < size; j++) {
			printWall(j, i, (dirNorth | dirWest), 1);
			printWall(j, i, (dirNorth), 3);
			printWall(j, i, (dirNorth | dirEast), 1);
		}
		std::cout << "\n";
		std::cout.width(2);
		std::cout << i << " ";
		for (int j = 0; j < size; j++) {
			printWall(j, i, (dirWest), 1);
			std::cout.width(3);
			std::cout << mazeWeights[j][i];
			printWall(j, i, (dirEast), 1);
		}
		std::cout << "\n";
	}
	cout << "   ";
	for (int j = 0; j < size; j++)
		printWall(j, 0, (dirSouth), 5);
	std::cout << "\n      0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15\n";
}

void Maze::printWall(int x, int y, int mask, int len) {
	int cell = getWalls({ x, y });
	char toPrint;
	if ((cell & mask) != 0)
		toPrint = (char)219; //219 is black rectangle
	else
		toPrint = ' ';
	for (int i = 0; i < len; i++)
		cout << toPrint;
}
