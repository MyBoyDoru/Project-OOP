#pragma once
#include "Shop.h"
#include <string>
#define MAX_ERR_CODES 4

using std::string;

class CLIController
{
public:
	//default constructor
	CLIController();
	//alternate constructor
	CLIController(const Shop& shop);
	//getter
	string getShopName() const { return this->controlledShop.getName(); }
	// todo: error handler
	string errorHandle();
	// todo: get user input
	void setUserInput(int);
	// todo: do logic stuff
	string logic();
	// todo: try and find the best way to spit out output
	// error code setter
	void setErrCode(int err_c) { this->errCode = err_c > 0 ? err_c : 0; }
private:
	Shop controlledShop;
	int tempUserInput, errCode;
};

