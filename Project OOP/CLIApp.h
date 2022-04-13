#pragma once
#include "Controller.h"
class CLIApp
{
public:
	CLIApp();
	CLIApp(Controller);
	void Start();
private:
	Controller controller;
};

