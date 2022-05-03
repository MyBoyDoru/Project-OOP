#include "CLIApp.h"
#include <iostream>
#ifdef _WIN_32
#include <Windows.h>
#endif

using std::cin;
using std::cout;
using std::endl;
using std::system;

CLIApp::CLIApp() : handler("temp.txt")
{
	this->controller = CLIController();
}

CLIApp::CLIApp(CLIController c, string handler) : handler(handler) {
	this->controller = c;
}

void CLIApp::clear()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void CLIApp::pause()
{
	#ifdef _WIN32
		system("pause");
	#else
		cout << "Press any key to continue...\n";
		system("read");
	#endif
}

void CLIApp::setup()
{
	this->pause();
	cout << "Component setup";
	cout << "Type of component";
	
}

void CLIApp::viewAll()
{
	cout << this->controller.getAllStr();
}

void CLIApp::Start()
{
    /// pre - checks if the user input is valid
    /// performs the needed operations
    /// post - checks if there are errors and if needed prints out the error
	cout << "Welcome to " << this->controller.getShopName() << endl;
    this->handler.save(this->controller.getShop());
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
			switch (opt)
			{
			case 1:
				this->viewAll();
				break;
			case 2:
				this->setup();
			case 0:
				cout << "See ya\n";
				exit(0);
				break;
			default:
				cout << "Wrong option!\n";
				break;
			}
        }
		cout << controller.errorHandle()<<endl;
		this->pause();
		this->clear();
	}
}