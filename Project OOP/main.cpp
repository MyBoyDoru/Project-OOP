#include <iostream>
#include "CLIApp.h"
#include "Controller.h"
#include "Shop.h"
using std::cout;

int main()
{
	CLIApp app(Controller(Shop("DenisTechs")));
	app.Start();
	return 0;
}