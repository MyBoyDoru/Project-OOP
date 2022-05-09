#pragma once
#include "Shop.h"
#include "FileHandler.h"
#include <string>
#define MAX_ERR_CODES 7

using std::string;
using std::to_string;
class CLIController
{
public:
	/// default constructor
	CLIController();
	/// alternate constructor
	/// @param [in] shop Custom controlled shop
	CLIController(const Shop& shop, string handler);
	//getters
    /// Gets the name of the shop
    /// @return A string containing the name of the shop
	string getShopName() const { return this->controlledShop.getName(); }
	// todo: error handler
    /// Handles errors and if needed prints out the errors
    /// @return A string containing a short description of the error and its code if needed, nothing otherwise
	string errorHandle(int errCode);
    Shop getShop(){return this->controlledShop;}
	/// <summary>
	/// Transforms the Items into a string form
	/// </summary>
	/// <returns>String with informations about the Items</returns>
	string getAllStr();
	void init();
	void cleanUp();
private:
    /// Controlled shop
	Shop controlledShop;
	FileHandler fileHandler; ///< The associated file handler for this app
	
};

