#include "CLIApp.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

CLIApp::CLIApp()
{
	this->controller = Controller();
}

CLIApp::CLIApp(Controller c)
{
	this->controller = c;
}

void CLIApp::Start()
{
	cout << "Welcome to " << this->controller.getShopName() << endl;

}