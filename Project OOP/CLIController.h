#pragma once
#include "Shop.h"
#include <string>
#define MAX_ERR_CODES 6

using std::string;
using std::to_string;
class CLIController
{
public:
	/// default constructor
	CLIController();
	/// alternate constructor
	/// @param [in] shop Custom controlled shop
	CLIController(const Shop& shop);
	//getters
    /// Gets the name of the shop
    /// @return A string containing the name of the shop
	string getShopName() const { return this->controlledShop.getName(); }
	// todo: error handler
    /// Handles errors and if needed prints out the errors
    /// @return A string containing a short description of the error and its code if needed, nothing otherwise
	string errorHandle(int errCode);
	// todo: get user input
    /// Sets the user input
    /// @param [in] opt User input, int that has to be between [0,2] (for now, more options will come later
	void setUserInput(int opt);
    Shop getShop(){return this->controlledShop;}
	/// <summary>
	/// Transforms the Items into a string form
	/// </summary>
	/// <returns>String with informations about the Items</returns>
	string getAllStr();
private:
    /// Controlled shop
	Shop controlledShop;
	int tempUserInput;
};

