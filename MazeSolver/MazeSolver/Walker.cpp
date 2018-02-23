#include "stdafx.h"
#include "Walker.h"


Walker::Walker(int size, point actualPoint) : size(size), actualPosition({ actualPoint, dirNorth })
{
}

Walker::Walker(int size, point actualPoint, directions dir) : size(size), actualPosition({ actualPoint, dir })
{
}


Walker::~Walker()
{
}

bool Walker::move(directions direction)
{
	switch (direction) {
	case dirNorth:
		if (actualPosition.coordinates.y < size - 1)
			actualPosition.coordinates.y++;
		else
			return false;
		break;
	case dirSouth:
		if (actualPosition.coordinates.y>0)
			actualPosition.coordinates.y--;
		else
			return false;
		break;
	case dirEast:
		if (actualPosition.coordinates.x<size - 1)
			actualPosition.coordinates.x++;
		else
			return false;
		break;
	case dirWest:
		if (actualPosition.coordinates.x>0)
			actualPosition.coordinates.x--;
		else
			return false;
		break;
	}
	actualPosition.looking_direction = direction;
	return true;
}

point Walker::getPoint(void)
{
	return actualPosition.coordinates;
}

position Walker::getPosition(void)
{
	return actualPosition;
}
