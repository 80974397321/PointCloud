//============================================================================
// Name        : FindingTheCenterOfaCloudOfPoints.cpp
// Author      : Dennis
// Version     :
// Copyright   : Hi everyone
// Description : Finding the center of the cloud of the points
//============================================================================

/*Ways of the task solving:
 * 1) As in example. Just 1 class (SetOfPoints), where we have set of point and which has the function to find the Center.
 * 2) As in 1, but the function must to use an object as an algorithm implementation. So its realization of the strategy pattern
 * 3) Use a complication structure. So, SetOfPoints need to have set of algorithms, where we can add a new one.
 * So we can use this class(SetOfPoints) in all tasks where we need sets of points by changing this set of algorithms.
 * 4) Use a wrap-pattern, which would have SetOfPoints and algorithms as a part of the wrap structure
 * 5) Use a class, which would take SetOfPoints as a parameter.
 * */


#include <iostream>
#include "CloudPoint/SetOfPoints.h"
#include "CloudPoint/MyFunctions.h"
#include <fstream>

typedef double MyDouble;


using namespace std;

int main(int par, char* args[]) {

if(par>1){
	SetOfPoints* setOfPoints = new SetOfPoints();
	if(setOfPoints->add(args[1], PARAM_FUNCTION_ADD_FILE))
	{}
	else
	{
		cout<<"no such file"<< endl;
		return 0;
	}
	//setOfPoints->add(2.0, 2.0);
	//setOfPoints->add(4.0, 6.0);
	Point2D centerOfACloudOfPoints = setOfPoints->findTheCenterOfACloudOfPoints();
	cout << centerOfACloudOfPoints.toString()<< endl; // prints !!!Hello World!!!
}
else
{
	cout<<"no file"<< endl;
	return 0;
}
}

