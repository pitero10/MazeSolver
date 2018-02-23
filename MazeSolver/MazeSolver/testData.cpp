#include "stdafx.h"
#include "Maze.h"
#include "MazeAlgorithm.h"

int codedWalls[16][16];

void addCodedWall(int x, int y, directions dir) {
	codedWalls[x][y] |= dir;
	Walker walker(16, { x, y });
	if (walker.move(dir))
		switch (dir) {
		case dirNorth:
			codedWalls[x][y + 1] |= dirSouth;
			break;
		case dirSouth:
			codedWalls[x][y - 1] |= dirNorth;
			break;
		case dirEast:
			codedWalls[x + 1][y] |= dirWest;
			break;
		case dirWest:
			codedWalls[x - 1][y] |= dirEast;
			break;
		}
}

int Maze::getCodedWalls(int x, int y) {
	return codedWalls[x][y];
}

void Maze::testData(void) {
	for (int i = 0; i < size; i++) {
		addCodedWall(i, 0, dirSouth);
		addCodedWall(i, size - 1, dirNorth);
		addCodedWall(0, i, dirWest);
		addCodedWall(size - 1, i, dirEast);
	}
	//addCodedWall(size / 2 - 1, size / 2 - 1, dirSouth);
	//addCodedWall(size / 2 - 1, size / 2 - 1, dirWest);
	//addCodedWall(size / 2, size / 2 - 1, dirSouth);
	//addCodedWall(size / 2, size / 2 - 1, dirEast);
	//addCodedWall(size / 2 - 1, size / 2, dirNorth);
	//addCodedWall(size / 2 - 1, size / 2, dirWest);
	//addCodedWall(size / 2, size / 2, dirNorth);
	//addCodedWall(size / 2 + 1, size / 2 + 1, dirEast);

	addCodedWall(0, 0, dirEast);
	addCodedWall(0, 1, dirEast);
	addCodedWall(0, 2, dirNorth);
	addCodedWall(0, 6, dirEast);
	addCodedWall(0, 7, dirEast);
	addCodedWall(0, 8, dirEast);
	addCodedWall(0, 9, dirEast);
	addCodedWall(0, 12, dirNorth);
	addCodedWall(0, 14, dirEast);
	addCodedWall(0, 15, dirEast);

	addCodedWall(1, 0, dirEast);
	addCodedWall(1, 1, dirEast);
	addCodedWall(1, 3, dirEast);
	addCodedWall(1, 3, dirNorth);
	addCodedWall(1, 4, dirNorth);
	addCodedWall(1, 5, dirNorth);
	addCodedWall(1, 7, dirEast);
	addCodedWall(1, 9, dirNorth);
	addCodedWall(1, 10, dirNorth);
	addCodedWall(1, 11, dirNorth);
	addCodedWall(1, 12, dirEast);
	addCodedWall(1, 14, dirEast);
	addCodedWall(1, 15, dirEast);

	addCodedWall(2, 0, dirEast);
	addCodedWall(2, 2, dirEast);
	addCodedWall(2, 3, dirEast);
	addCodedWall(2, 4, dirEast);
	addCodedWall(2, 4, dirNorth);
	addCodedWall(2, 5, dirNorth);
	addCodedWall(2, 7, dirNorth);
	addCodedWall(2, 8, dirNorth);
	addCodedWall(2, 9, dirNorth);
	addCodedWall(2, 10, dirNorth);
	addCodedWall(2, 11, dirEast);
	addCodedWall(2, 12, dirEast);
	addCodedWall(2, 13, dirEast);
	addCodedWall(2, 15, dirEast);

	addCodedWall(3, 1, dirEast);
	addCodedWall(3, 2, dirEast);
	addCodedWall(3, 3, dirEast);
	addCodedWall(3, 4, dirEast);
	addCodedWall(3, 5, dirEast);
	addCodedWall(3, 5, dirNorth);
	addCodedWall(3, 6, dirNorth);
	addCodedWall(3, 7, dirNorth);
	addCodedWall(3, 8, dirNorth);
	addCodedWall(3, 9, dirNorth);
	addCodedWall(3, 10, dirEast);
	addCodedWall(3, 11, dirEast);
	addCodedWall(3, 12, dirEast);
	addCodedWall(3, 13, dirEast);
	addCodedWall(3, 14, dirEast);


	addCodedWall(4, 0, dirNorth);
	addCodedWall(4, 2, dirEast);
	addCodedWall(4, 3, dirEast);
	addCodedWall(4, 4, dirEast);
	addCodedWall(4, 5, dirEast);
	addCodedWall(4, 6, dirEast);
	addCodedWall(4, 6, dirNorth);
	addCodedWall(4, 7, dirNorth);
	addCodedWall(4, 8, dirNorth);
	addCodedWall(4, 9, dirEast);
	addCodedWall(4, 10, dirEast);
	addCodedWall(4, 11, dirEast);
	addCodedWall(4, 12, dirEast);
	addCodedWall(4, 13, dirEast);
	addCodedWall(4, 14, dirNorth);

	addCodedWall(5, 0, dirNorth);
	addCodedWall(5, 1, dirNorth);
	addCodedWall(5, 3, dirEast);
	addCodedWall(5, 4, dirEast);
	addCodedWall(5, 5, dirEast);
	addCodedWall(5, 6, dirEast);
	addCodedWall(5, 7, dirEast);
	addCodedWall(5, 7, dirNorth);
	addCodedWall(5, 8, dirEast);
	addCodedWall(5, 10, dirEast);
	addCodedWall(5, 12, dirNorth);
	addCodedWall(5, 13, dirNorth);
	addCodedWall(5, 14, dirNorth);

	addCodedWall(6, 0, dirNorth);
	addCodedWall(6, 1, dirNorth);
	addCodedWall(6, 2, dirNorth);
	addCodedWall(6, 4, dirNorth);
	addCodedWall(6, 7, dirNorth);
	addCodedWall(6, 7, dirEast);
	addCodedWall(6, 8, dirEast);
	addCodedWall(6, 10, dirNorth);
	addCodedWall(6, 11, dirNorth);
	addCodedWall(6, 12, dirNorth);
	addCodedWall(6, 13, dirNorth);
	addCodedWall(6, 14, dirNorth);

	addCodedWall(7, 0, dirNorth);
	addCodedWall(7, 1, dirNorth);
	addCodedWall(7, 2, dirNorth);
	addCodedWall(7, 3, dirNorth);
	addCodedWall(7, 4, dirNorth);
	addCodedWall(7, 5, dirNorth);
	addCodedWall(7, 6, dirNorth);
	addCodedWall(7, 8, dirNorth);
	addCodedWall(7, 9, dirNorth);
	addCodedWall(7, 9, dirEast);
	addCodedWall(7, 11, dirNorth);
	addCodedWall(7, 12, dirNorth);
	addCodedWall(7, 13, dirNorth);
	addCodedWall(7, 14, dirNorth);

	addCodedWall(8, 0, dirNorth);
	addCodedWall(8, 1, dirNorth);
	addCodedWall(8, 2, dirNorth);
	addCodedWall(8, 3, dirNorth);
	addCodedWall(8, 4, dirNorth);
	addCodedWall(8, 5, dirNorth);
	addCodedWall(8, 6, dirNorth);
	addCodedWall(8, 7, dirEast);
	addCodedWall(8, 8, dirEast);
	addCodedWall(8, 9, dirNorth);
	addCodedWall(8, 10, dirNorth);
	addCodedWall(8, 13, dirNorth);
	addCodedWall(8, 13, dirEast);
	addCodedWall(8, 14, dirNorth);

	addCodedWall(9, 0, dirNorth);
	addCodedWall(9, 1, dirNorth);
	addCodedWall(9, 2, dirNorth);
	addCodedWall(9, 3, dirNorth);
	addCodedWall(9, 4, dirNorth);
	addCodedWall(9, 5, dirNorth);
	addCodedWall(9, 6, dirEast);
	addCodedWall(9, 9, dirEast);
	addCodedWall(9, 9, dirNorth);
	addCodedWall(9, 10, dirEast);
	addCodedWall(9, 11, dirNorth);
	addCodedWall(9, 11, dirEast);
	addCodedWall(9, 12, dirEast);
	addCodedWall(9, 13, dirNorth);
	addCodedWall(9, 14, dirNorth);

	addCodedWall(10, 0, dirNorth);
	addCodedWall(10, 1, dirNorth);
	addCodedWall(10, 2, dirNorth);
	addCodedWall(10, 3, dirNorth);
	addCodedWall(10, 4, dirNorth);
	addCodedWall(10, 5, dirNorth);
	addCodedWall(10, 7, dirNorth);
	addCodedWall(10, 8, dirNorth);
	addCodedWall(10, 10, dirNorth);
	addCodedWall(10, 12, dirNorth);
	addCodedWall(10, 13, dirNorth);
	addCodedWall(10, 14, dirNorth);

	addCodedWall(11, 0, dirNorth);
	addCodedWall(11, 1, dirNorth);
	addCodedWall(11, 2, dirNorth);
	addCodedWall(11, 3, dirNorth);
	addCodedWall(11, 4, dirNorth);
	addCodedWall(11, 5, dirEast);
	addCodedWall(11, 6, dirNorth);
	addCodedWall(11, 7, dirNorth);
	addCodedWall(11, 8, dirNorth);
	addCodedWall(11, 9, dirNorth);
	addCodedWall(11, 10, dirNorth);
	addCodedWall(11, 11, dirNorth);
	addCodedWall(11, 12, dirNorth);
	addCodedWall(11, 13, dirNorth);
	addCodedWall(11, 14, dirNorth);

	addCodedWall(12, 0, dirNorth);
	addCodedWall(12, 1, dirNorth);
	addCodedWall(12, 2, dirNorth);
	addCodedWall(12, 3, dirNorth);
	addCodedWall(12, 4, dirNorth);
	addCodedWall(12, 7, dirNorth);
	addCodedWall(12, 8, dirNorth);
	addCodedWall(12, 9, dirNorth);
	addCodedWall(12, 10, dirNorth);
	addCodedWall(12, 11, dirNorth);
	addCodedWall(12, 12, dirNorth);
	addCodedWall(12, 13, dirNorth);
	addCodedWall(12, 14, dirNorth);

	addCodedWall(13, 0, dirNorth);
	addCodedWall(13, 1, dirNorth);
	addCodedWall(13, 2, dirNorth);
	addCodedWall(13, 3, dirNorth);
	addCodedWall(13, 4, dirNorth);
	addCodedWall(13, 5, dirNorth);
	addCodedWall(13, 6, dirNorth);
	addCodedWall(13, 7, dirNorth);
	addCodedWall(13, 8, dirEast);
	addCodedWall(13, 9, dirEast);
	addCodedWall(13, 9, dirNorth);
	addCodedWall(13, 10, dirEast);
	addCodedWall(13, 11, dirEast);
	addCodedWall(13, 11, dirNorth);
	addCodedWall(13, 12, dirNorth);
	addCodedWall(13, 13, dirNorth);
	addCodedWall(13, 14, dirNorth);

	addCodedWall(14, 0, dirNorth);
	addCodedWall(14, 1, dirNorth);
	addCodedWall(14, 2, dirEast);
	addCodedWall(14, 3, dirEast);
	addCodedWall(14, 3, dirNorth);
	addCodedWall(14, 5, dirEast);
	addCodedWall(14, 6, dirEast);
	addCodedWall(14, 7, dirNorth);
	addCodedWall(14, 8, dirEast);
	addCodedWall(14, 9, dirEast);
	addCodedWall(14, 10, dirEast);
	addCodedWall(14, 11, dirEast);
	addCodedWall(14, 12, dirEast);
	addCodedWall(14, 13, dirEast);
	addCodedWall(14, 13, dirNorth);
	addCodedWall(14, 14, dirNorth);

	addCodedWall(15, 1, dirNorth);
	addCodedWall(15, 7, dirNorth);


	//addCodedWall(0, 2, dirEast);
	//addCodedWall(0, 3, dirNorth);
	//addCodedWall(1, 3, dirNorth);
	//addCodedWall(1, 3, dirSouth);
	//addCodedWall(2, 3, dirNorth);
	//addCodedWall(2, 3, dirSouth);
	//addCodedWall(3, 3, dirNorth);
	//addCodedWall(3, 3, dirSouth);
	//addCodedWall(4, 3, dirNorth);
	//addCodedWall(4, 3, dirSouth);
	//addCodedWall(5, 3, dirNorth);
	//addCodedWall(5, 3, dirSouth);

	//addCodedWall(6, 3, dirSouth);
	//addCodedWall(6, 3, dirEast);

	//addCodedWall(6, 4, dirWest);
	//addCodedWall(6, 4, dirEast);

	//addCodedWall(6, 5, dirNorth);
	//addCodedWall(6, 5, dirEast);


	//addCodedWall(10, 9, dirSouth);
	//addCodedWall(11, 9, dirSouth);
	//addCodedWall(12, 9, dirSouth);

	//addCodedWall(8, 10, dirWest);
	//addCodedWall(8, 11, dirWest);
}