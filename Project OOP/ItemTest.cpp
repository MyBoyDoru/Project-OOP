#include "ItemTest.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include <assert.h>

using std::cout;
using std::vector;

bool fcmp(float a, float b)
{
	if (abs(a - b) < 0.0005)
		return true;
	return false;
}

ItemTest::ItemTest()
{
	this->depth = 1;
}

ItemTest::ItemTest(int level)
{
	this->depth = level;
}

void ItemTest::runTests()
{
	if (this->depth == 1)
	{
		this->testConstructor();
		this->testTransformation();
		this->testPolimorphism();
		cout << "Item test... " << GRN << "OK" << NC << "\n";
	}
	else
	{
		cout << "Item test\n";
		this->testConstructor();
		cout << "	Constructor test... " << GRN << "OK" << NC << "\n";
		this->testTransformation();
		cout << "	Transformation test... " << GRN << "OK" << NC << "\n";
		this->testPolimorphism();
		cout << "	Polimorphism test... " << GRN << "OK" << NC << "\n";

	}
	
}

void ItemTest::testConstructor()
{
	Item a;
	assert(a.getId() == -1);
	assert(a.getPrice() == -1);
	assert(a.getName() == "");
	assert(a.getType() == "ITEM");
	Item b(3, "test", 10.99);
	assert(b.getId() == 3);
	assert(fcmp(b.getPrice(), 10.99));
	assert(b.getName() == "test");
	assert(b.getType() == "ITEM");

}

void ItemTest::testTransformation()
{
	Item a(1,"test", 10.99);
	assert(a.toString() == "1 - test, 10.99$");
	assert(a.toCSV() == "1,test,10.99");
	Item b;
	assert(b.toString() == "-1 - , -1.00$");
	assert(b.toCSV() == "-1,,-1");
}

void ItemTest::testPolimorphism()
{
	vector<Item*> a;
	a.push_back(new CPU(1, "test", 10, "test", 4, 3.4));
	assert(a[0]->getType() == "CPU");
	assert(a[0]->toString() == "1 - test test, 4 cores, @3.40 gHz, 10.00$");
	assert(a[0]->toCSV() == "1,test,10,test,4,3.4");

	a.push_back(new GPU(1, "test", 10, "test", 1850, 4));
	assert(a[1]->getType() == "GPU");
	assert(a[1]->toString() == "1 - test test, @1850hz, with 4 GB of VRAM, 10.00$");
	assert(a[1]->toCSV() == "1,test,10,test,1850,4");

	a.push_back(new RAM(1, "test", 10, "test", 3200, 4,2));
	assert(a[2]->getType() == "RAM");
	assert(a[2]->toString() == "1 - test test, @3200hz, with 4 GB of DRAM, with a 2*2 configuration, 10.00$");
	assert(a[2]->toCSV() == "1,test,10,test,3200,4,2");

	a.push_back(new PSU(1, "test", 10, "test", 500, "80 Bronze"));
	assert(a[3]->getType() == "PSU");
	assert(a[3]->toString() == "1 - test test, 500W, rated 80 Bronze, 10.00$");
	assert(a[3]->toCSV() == "1,test,10,test,500,80 Bronze");

	a.push_back(new PSU(1, "test", 10, "test", 500, "80 Bronze"));
	assert(a[3]->getType() == "PSU");
	assert(a[3]->toString() == "1 - test test, 500W, rated 80 Bronze, 10.00$");
	assert(a[3]->toCSV() == "1,test,10,test,500,80 Bronze");

}
