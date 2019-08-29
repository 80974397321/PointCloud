#include "D:\prog\PhotonWorkspace\CloudPointRepository\CloudPointDev\cute\cute.h"
#include "D:\prog\PhotonWorkspace\CloudPointRepository\CloudPointDev\cute\ide_listener.h"
#include "D:\prog\PhotonWorkspace\CloudPointRepository\CloudPointDev\cute\xml_listener.h"
#include "D:\prog\PhotonWorkspace\CloudPointRepository\CloudPointDev\cute\cute_runner.h"

#include <fstream>
#include <vector>
#include <string.h>
#include <functional>

#include "CloudOfPoints/Point2D.h"
#include "PointParse.h"

#define EQUALITY_PRESICION 0.000001

Point2D a, b, ops[4];
std::string tostring;
char testcasePath[] = "TestCases/CloudPoint/Point2D/test1.txt"



void SetUp()
{
	ifstream infile(testcasePath);

	std::string s;

	std::getline(infile, s);
	a = getPointFromString(s.c_str());

	std::getline(infile, s);
	b = getPointFromString(s.c_str());

	std::getline(infile, s);
	for (int i = 0; i < 4; i++)
	{
		std::getline(infile, s);
		ops[i] = getPointFromString(s.c_str());
	}

	std::getline(infile, tostring);
	close(infile);
}

void indexOperator()
{
	Point2D p;
	float x = 11, y = 5;
	p[POINT2D_X] = x;
	p[POINT2D_Y] = y;

	bool result = (p[POINT2D_X] - x <= EQUALITY_PRESICION) && (p[POINT2D_Y] - y <= EQUALITY_PRESICION);
	ASSERTM("Index operator is inconsistent", result);
}

void sum()
{
	bool result = distance(a + b, ops[0]) <= EQUALITY_PRESICION;
	ASSERTM("Sum failed", result);
}

void subst()
{
	bool result = distance(a + b, ops[1]) <= EQUALITY_PRESICION;
	ASSERTM("Subtraction failed", result);
}
void mult()
{
	bool result = distance(a + b, ops[2]) <= EQUALITY_PRESICION;
	ASSERTM("Multiplication failed", result);
}
void div()
{
	bool result = distance(a + b, ops[3]) <= EQUALITY_PRESICION;
	ASSERTM("Division failed", result);
}

void str()
{
	ASSERT_EQUALM("To string operation failes", tostring, a.toString());
}

bool runAllTests(int argc, char const *argv[])
{
	cute::suite s { };
	s.push_back(CUTE(indexOperator));
	s.push_back(CUTE(sum));
	s.push_back(CUTE(subst));
	s.push_back(CUTE(mult));
	s.push_back(CUTE(div));
	s.push_back(CUTE(str));

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}
