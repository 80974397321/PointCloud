#include "UnitTest.h"

#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include <fstream>
#include <vector>
#include <string.h>
#include <functional>

#include "TestCodes/SetOfPoints.h"

Point2D getPointFromString(const char* s)
{
	Point2D result;
	char* toParse = new char[strlen(s) + 1];
	strcpy(toParse, s);
	char* temp;

	temp = strtok(toParse, " ");
	result.x = stod(temp);

	temp = strtok(0, " ");
	result.y = stod(temp);

	return result;
}

void TestRun(int pff)
{
	char* filename = new char[30];
	char* n = new char[10];
	itoa(pff, n, 10);

	strcpy(filename, "src/TestCases/test");
	strcat(filename, n);
	strcat(filename, ".txt");


	ifstream infile(filename);

	SetOfPoints* set = new SetOfPoints();

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
	Point2D diff = set->findTheCenterOfACloudOfPoints() - expected;

	double d = sqrt(diff.x * diff.x + diff.y * diff.y);
	ASSERT_EQUAL_DELTA(0, d, 0.00001);

}

//std::string f = "TestCases/test1.txt";

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

int main(int argc, char const *argv[])
{
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
