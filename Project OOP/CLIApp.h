#pragma once
#include "CLIController.h"
class CLIApp
{
public:
	// default constructor for the CLI app
	CLIApp();
	// alternate constructor with controller
	CLIApp(CLIController);
	// starts the loop
	void Start();
private:
	CLIController controller;
	void clear();
	void pause();
};

