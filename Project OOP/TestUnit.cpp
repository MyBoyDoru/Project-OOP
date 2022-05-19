#include "TestUnit.h"
#include <iostream>

using std::cout;

TestUnit::TestUnit(int level)
{
	this->depth = level;
	this->itemTest  = ItemTest(level);
}

void TestUnit::runTests()
{
	this->itemTest.runTests();
	cout << "ALL TESTS " << GRN << "OK" << NC << "\n";
}
