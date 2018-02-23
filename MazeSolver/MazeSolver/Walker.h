#pragma once

typedef enum {
	dirNorth = 0x01,
	dirSouth = 0x02,
	dirEast = 0x04,
	dirWest = 0x08,
	dirMask = 0x0F
} directions;

typedef struct {
	int x;
	int y;
} point;

typedef struct {
	point coordinates;
	directions looking_direction;
} position;

class Walker
{
	int size;
	position actualPosition;
public:
	Walker(int size, point actualPoint);
	Walker(int size, point actualPoint, directions dir);
	~Walker();
	bool move(directions direction);
	point getPoint(void);
	position getPosition(void);
};

