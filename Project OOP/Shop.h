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
	Shop();
	//alternate constructor
	Shop(string name);
	//copy constructor
	Shop(const Shop& other);
	//add an element and its stock to the repository
	void addElem(Component c, int stock, int& err_c);
	//search for a given element and return its position in the vector
	//-1 if not found
	int internalSearch(Component c);
	// getters
	string getName() const { return this->name; }
	
	Shop operator=(const Shop other);
private:
	//name of the shop
	string name;
	//size of the vector
	int sz;
	//the vector will remember both the component type and the stock status of the component
	vector<pair<Component, int>> sell;

};

