/*
 * SetOfPoints.cpp
 *
 *  Created on: Aug 19, 2019
 *      Author: u1
 */

#include "CloudPoint/SetOfPoints.h"

SetOfPoints::SetOfPoints() {
	// TODO Auto-generated constructor stub

}
MyBool SetOfPoints::add(MyDouble x, MyDouble y)
{
	Point2D p;
	p.x=x;
	p.y=y;
	setOfPoints.push_back(p);
	return true;
}

MyBool SetOfPoints::add(Point2D p)
{
	setOfPoints.push_back(p);
	return true;
}

MyBool SetOfPoints::add(MyString text, MyInt parType)
{
	ifstream infile(text);
	if (! infile)
	{
		return false;
	}
	string str;
	vector<string> temp;
	while(std::getline(infile,str))
	{
		MyFunctions::split(str,temp,' ');
		Point2D p;
		p.x = stod(temp[0]);
		p.y = stod(temp[1]);
		temp.clear();
		setOfPoints.push_back(p);
	}
	infile.close();
	return true;
}
Point2D SetOfPoints::findTheCenterOfACloudOfPoints()
{
	Point2D answ;
	Point2D helpNum;
	helpNum.x=0.0;
	helpNum.y=0.0;
	answ.x=0.0;
	answ.y=0.0;
	for(Point2D d:setOfPoints)
	{
		helpNum=helpNum+d;
	}
	answ=helpNum/(MyInt)setOfPoints.size();
	return answ;
}
SetOfPoints::~SetOfPoints() {
	// TODO Auto-generated destructor stub
}

