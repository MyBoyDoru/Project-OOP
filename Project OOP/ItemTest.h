#pragma once
#define NC "\033[0m"
#define NC "\033[0m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"

class ItemTest
{
public:
	ItemTest();
	ItemTest(int level);
	void runTests();
private:
	int depth;
	void testConstructor();
	void testTransformation();
	void testPolimorphism();
};

