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
	while (true)
	{
		cout << "1. View the inventory\n";
		cout << "2. Add an item to the inventory\n";
		cout << "0. Exit\n";
		int opt;
		if (!(cin>>opt))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			this->controller.setErrCode(3);
		}
		else
		{
			this->controller.setUserInput(opt);
			cout << controller.logic();
		}
		cout << controller.errorHandle()<<endl;
	}
}