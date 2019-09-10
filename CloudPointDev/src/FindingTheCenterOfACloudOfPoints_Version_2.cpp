//============================================================================
// Name        : FindingTheCenterOfACloudOfPoints_Version_2.cpp
// Author      : Dennis Ohrimchuck
// Version     :
// Copyright   : Hi everyone
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CloudOfPoints/Point2D.h"
#include "CloudOfPoints/MyFunctions.h"
#include "CloudOfPoints/AbstractAlgorithm.h"
#include "CloudOfPoints/AlgorithmFindTheCenterOfTheMass.h"
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <fstream>

#define FIND_THE_CENTER_OF_THE_MASS 1

typedef int MyInt;
typedef double MyDouble;
typedef Point2D PointType;
typedef std::string MyString;

using namespace std;

template <class ItemType, class AnswerType>
AbstractAlgorithm<ItemType, AnswerType>* classFactory(MyInt indexOfAlg)
{
	switch(indexOfAlg)
	{
	case FIND_THE_CENTER_OF_THE_MASS:
		return new AlgorithmFindTheCenterOfTheMass<ItemType,AnswerType>();
	default:
		return new AlgorithmFindTheCenterOfTheMass<ItemType, AnswerType>();

	}
}

/*
template <class T>
void example(T& a, MyDouble b)
{
	a[0]=b;
}*/
template <class T>
bool loadPointToAlgFromFile(AlgString text, AbstractAlgorithm<T, T>* alg)
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
				T p;
				p[0] = stod(temp[0]);
				p[1] = stod(temp[1]);
				temp.clear();
				alg->add(p);
			}
			infile.close();
			return true;
	}

int main(int par, char* args[]) {
	if(par>1){
		//You cannot use abstract class this way, so i cant setup AbstractAlgorithm as abstract class
		AbstractAlgorithm<PointType, PointType>* alg = classFactory<PointType, PointType>(FIND_THE_CENTER_OF_THE_MASS);
		for(int i=1; i<par; i++)
		{
			//if(AbstractAlgorithm::template loadPointToAlgFromFile<PointType>(args[i], &alg))
			if(loadPointToAlgFromFile<PointType>(args[i], alg))
			{}
			else
			{
				cout<<"no such file"<< endl;
				return 0;
			}
		}
		//setOfPoints->add(2.0, 2.0);
		//setOfPoints->add(4.0, 6.0);
		cout<<(alg->getResult()).toString();
	}
	else
	{

		cout<<"no file"<< endl;
		return 0;
	}


	return 0;
}
