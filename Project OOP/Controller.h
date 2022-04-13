#pragma once
#include "Shop.h"
#include <string>

using std::string;

class Controller
{
public:
	//default constructor
	Controller();
	//alternate constructor
	Controller(const Shop& shop);
	//getter
	string getShopName() const { return this->controlledShop.getName(); }
	// todo: error handler
	// todo: get user input
	// todo: do logic stuff
	// todo: try and find the best way to spit out output
private:
	Shop controlledShop;
};

