/*
 * SetOfPoints.h
 *
 *  Created on: Aug 19, 2019
 *      Author: u1
 */

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include "MyFunctions.h"
#include <fstream>

#ifndef SETOFPOINTS_H_
#define SETOFPOINTS_H_

#define PARAM_FUNCTION_ADD_FILE 1
#define PARAM_FUNCTION_ADD_TEXT_WITH_POINTS 1

typedef double MyDouble;
typedef bool MyBool;
typedef int MyInt;
typedef std::string MyString;

using namespace std;

struct Point2D
{
	MyDouble x,y;
	Point2D(MyDouble x=0, MyDouble y=0):x(x),y(y){}
	MyString toString()
	{
		return to_string(x)+" ; "+to_string(y);
	}
	Point2D operator +(const Point2D& a)
	{
		Point2D answ;
		answ.x=a.x+x;
		answ.y=a.y+y;
		return answ;
	};
	Point2D operator -(const Point2D& a)
	{
		Point2D answ;
		answ.x=x-a.x;
		answ.y=y-a.y;
		return answ;
	};
	Point2D operator /(const MyDouble& a)
	{
		Point2D answ;
		answ.x=x/a;
		answ.y=y/a;
		return answ;
	};
	Point2D operator *(const MyDouble& a)
	{
		Point2D answ;
		answ.x=x*a;
		answ.y=y*a;
		return answ;
	};

};

class SetOfPoints {
private:
	vector<Point2D> setOfPoints;
public:
	SetOfPoints();
	MyBool add(MyDouble x, MyDouble y);
	MyBool add(Point2D p);
	MyBool add(MyString text, MyInt parType);
	Point2D findTheCenterOfACloudOfPoints();
	virtual ~SetOfPoints();
};

#endif /* SETOFPOINTS_H_ */
