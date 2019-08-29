#ifndef POINTPARSE_H_
#define POINTPARSE_H_

#include "CloudOfPoints/Point2D.h"

Point2D getPointFromString(const char* s)
{
	Point2D result;
	char* toParse = new char[strlen(s) + 1];
	strcpy(toParse, s);
	char* temp;

	temp = strtok(toParse, " ");
	result[POINT2D_X] = stod(temp);

	temp = strtok(0, " ");
	result[POINT2D_Y] = stod(temp);

	return result;
}

float distance(Point2D p1, Point2D p2)
{
	float dx = p1[POINT2D_X] - p2[POINT2D_X],
		  dy = p1[POINT2D_Y] - p2[POINT2D_Y];

	float d = dx * dx + dy * dy;
	return sqrt(d);
}
#endif
