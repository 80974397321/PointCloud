#ifndef TESTMASSCENTERAGL_H_
#define TESTMASSCENTERAGL_H_

#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <fstream>
#include <vector>
#include <string.h>
#include <functional>

#include <iostream>

using namespace std;

#include "CloudOfPoints/AlgorithmFindTheCenterOfTheMass.h"
#include "Utils/PointParse.h"


void TestRun(int pff)
{
	char* filename = new char[100];
	char* n = new char[10];
	itoa(pff, n, 10);

	strcpy(filename, "TestCases/PointCloud/MassCenterAlgorythm/test");
	strcat(filename, n);
	strcat(filename, ".txt");

	ifstream infile(filename);

	AlgorithmFindTheCenterOfTheMass<Point2D, Point2D>* set = new AlgorithmFindTheCenterOfTheMass<Point2D, Point2D>();

	std::string s;

	while(std::getline(infile, s))
	{
		if(s == "")
		{
			break;
		}
		else
		{
			set->add(getPointFromString(s.c_str()));
		}
	}

	std::getline(infile, s);
	Point2D expected = getPointFromString(s.c_str());

	infile.close();

	auto result = set->getResult();

	double d = distance(result, expected);
	//ASSERT_EQUAL_DELTA(0, d, 0.00001);
	delete set;
	cout << d;
	ASSERT(abs(d) < 0.0001);

}

bool runAllTests(int argc, char const *argv[])
{
	cute::suite s { };
	for (int i = 1; i < 6; i++)
	{
		auto f = std::bind(TestRun, i);
		s.push_back(f);
	}
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

#endif
