#pragma once
#include <vector>
#include <string>
#include "Component.h"

using std::vector;
using std::string;
using std::pair;
using std::make_pair;

class Shop
{
public:
	//default constructor
	Shop(string name);
	//copy constructor
	Shop(const Shop& other);
	void addElem(Component c, int stock, int& err_c);
	int internalSearch(Component c);
private:
	//name of the shop
	string name;
	//size of the vector
	int sz;
	//the vector will remember both the component type and the stock status of the component
	vector<pair<Component, int>> sell;

};

