#pragma once
#include "ItemTest.h"

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"

class TestUnit
{
public:
	TestUnit(int level = 1);
	void runTests();
private:
	ItemTest itemTest;
	int depth;
	
};

