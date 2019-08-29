#ifndef TESTMYFUNCTIONS_H_
#define TESTMYFUNCTIONS_H_


#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <fstream>
#include <vector>
#include <string.h>

#include "CloudOfPoints/MyFunctions.h"


std::string input;
vector<std::string> expected, result;
char separator = '|';
char testcasePath[] = "TestCases/PointCloud/MyFunctions/test1.txt";



void setUp()
{
	ifstream infile(testcasePath);

	std::string s;
	std::getline(infile, input);

	std::getline(infile, s);
	while(std::getline(infile, s))
	{
		expected.push_back(s);
	}

	infile.close();
}

void test()
{
	MyFunctions::split(input, result, separator);

	ASSERTM("Split failed", result == expected);
}

bool runAllTests(int argc, char const *argv[])
{
	setUp();
	cute::suite s { };
	s.push_back(CUTE(test));

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

#endif
