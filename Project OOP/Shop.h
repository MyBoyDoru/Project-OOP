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
	Shop(string name, vector<pair<Item*, int>> vec);
	//copy constructor
	Shop(const Shop& other);
	//add an element and its stock to the repository
	void addElem(Item c, int stock, int& err_c);
	//search for a given element and return its position in the vector
	//-1 if not found
	int internalSearch(Item c);
	// getters
	// gets the name
	string getName() const { return this->name; }
	// gets the size
	int getSz() const { return this->sz; }
	// gets an item and its stock
	pair<Item*,int> get(int x,int & err_c);
	// = operator
	Shop operator=(const Shop other);
private:
	//name of the shop
	string name;
	//size of the vector
	int sz;
	//the vector will remember both the component type and the stock status of the component
	vector<pair<Item*, int>> sell;

};

