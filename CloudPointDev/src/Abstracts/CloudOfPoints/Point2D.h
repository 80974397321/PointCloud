/*
 * Point2D.h
 *
 *  Created on: Aug 25, 2019
 *      Author: u1
 */

#ifndef POINT2D_H_
#define POINT2D_H_

#include <string>
#include <vector>
#include <string.h>

#define POINT2D_X 0
#define POINT2D_Y 1

typedef double Point2DFloat;
typedef int Point2DInt;

using namespace std;

class Point2D {
private:
	Point2DFloat p[2];
public:

	Point2DFloat& operator[](Point2DInt num) {
		if(num==0 || num == 1){
			return ((Point2DFloat*)p)[num];
		}
		else
		{
			return ((Point2DFloat*)p)[0];
		}
	}
	Point2D();
	virtual ~Point2D();
	string toString()
	{
		return to_string(p[POINT2D_X])+" ; "+to_string(p[POINT2D_Y]);
	}
	Point2D operator +(Point2D& a)
	{
		Point2D answ;
		answ[POINT2D_X]=a[POINT2D_X]+p[POINT2D_X];
		answ[POINT2D_Y]=a[POINT2D_Y]+p[POINT2D_Y];
		return answ;
	};
	Point2D operator -(Point2D& a)
	{
		Point2D answ;
		answ[POINT2D_X]=p[POINT2D_X]-a[POINT2D_X];
		answ[POINT2D_Y]=p[POINT2D_Y]-a[POINT2D_Y];
		return answ;
	};
	Point2D operator /(const double& a)
	{
		Point2D answ;
		answ[POINT2D_X]=p[POINT2D_X]/a;
		answ[POINT2D_Y]=p[POINT2D_Y]/a;
		return answ;
	};
	Point2D operator *(const double& a)
	{
		Point2D answ;
		answ[POINT2D_X]=p[POINT2D_X]*a;
		answ[POINT2D_Y]=p[POINT2D_Y]*a;
		return answ;
	};
};

#endif /* POINT2D_H_ */
