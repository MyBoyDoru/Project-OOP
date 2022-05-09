#pragma once
#include "CLIController.h"

class CLIApp
{
public:
	/// Default constructor for the CLI app
	CLIApp();
    /// Alternate constructor with controller
    /// @param [in] CLIController Controller associated to the CLIApp class
    CLIApp(CLIController c);
	/// Starts the loop
    void Start();
	void addElement(Item* x, int stock);
private:

	CLIController controller; ///< The associated controller for this app
    
	void clear(); ///< Cross platform clear function
	void pause(); ///< Cross platform pause function
	/// <summary>
	/// Sets up an Item to be added to the inventory
	/// </summary>
	void setup();
	void viewAll();
};

