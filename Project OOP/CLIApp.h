#pragma once
#include "CLIController.h"
#include "FileHandler.h"

class CLIApp
{
public:
	/// Default constructor for the CLI app
	CLIApp();
    /// Alternate constructor with controller
    /// @param [in] CLIController Controller associated to the CLIApp class
    CLIApp(CLIController c, string handler);
	/// Starts the loop
    void Start();
private:
	CLIController controller; ///< The associated controller for this app
    FileHandler handler; ///< The associated file handler for this app
	void clear(); ///< Cross platform clear function
	void pause(); ///< Cross platform pause function
};

