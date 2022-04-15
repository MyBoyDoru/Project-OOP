#pragma once
#include "Controller.h"
class CLIApp
{
public:
	// default constructor for the CLI app
	CLIApp();
	// alternate constructor with controller
	CLIApp(Controller);
	// starts the loop
	void Start();
private:
	Controller controller;
};

