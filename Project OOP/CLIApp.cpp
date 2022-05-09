#include "CLIApp.h"
#include <iostream>
#ifdef _WIN_32
#include <Windows.h>
#endif
 /// commit here
using std::cin;
using std::cout;
using std::endl;
using std::system;

CLIApp::CLIApp() 
{
	this->controller = CLIController();
}

CLIApp::CLIApp(CLIController c)
{
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
	cout << "Type of component(CPU, GPU, RAM, PSU, Storage, MOBO, Case): ";
    string type;
    cin >> type;
    if (type == "CPU")
    {
        int id, coreCount, stock;
        float price, frequency;
        string brand, name;
        cout << "ID: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "Brand: "; cin >> brand;
        cout << "Core count: "; cin >> coreCount;
        cout << "Frequency: "; cin>>frequency;
        cout << "Price: "; cin >> price;
        cout << "Stock: "; cin >> stock;
        this->addElement(new CPU(id, name, price, brand, coreCount, frequency), stock);
    }
    else if (type == "GPU")
    {
        int id, VRAM, stock, frequency;
        float price;
        string brand, name;
        cout << "ID: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "Brand: "; cin >> brand;
        cout << "Frequency: "; cin >> frequency;
        cout << "VRAM: "; cin >> VRAM;
        cout << "Price: "; cin >> price;
        cout << "Stock: "; cin >> stock;
        this->addElement(new GPU(id, name, price, brand, frequency, VRAM), stock);
    }
    else if (type == "RAM")
    {
        int id, DRAM, modules, stock, frequency;
        string name, brand, aux;
        float price;
        cout << "ID: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "Brand: "; cin >> brand;
        cout << "Frequency: "; cin >> frequency;
        cout << "DRAM: "; cin >> DRAM;
        cout << "Modules: "; cin >> modules;
        cout << "Price: "; cin >> price;
        cout << "Stock: "; cin >> stock;
        this->addElement(new RAM(id, name, price, brand, frequency, DRAM, modules), stock);
    }
    else if (type == "PSU")
    {
        int id, wattage, stock;
        string name, brand, aux, rating;
        float price;
        cout << "ID: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "Brand: "; cin >> brand;
        cout << "Wattage: "; cin >> wattage;
        cout << "Rating: "; cin >> rating;
        cout << "Price: "; cin >> price;
        cout << "Stock: "; cin >> stock;
        this->addElement(new PSU(id, name, price, brand, wattage, rating), stock);
    }
    else if (type == "Storage")
    {
        int id, storage, kind, stock;
        string name, brand, aux;
        float price;
        cout << "ID: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "Brand: "; cin >> brand;
        cout << "Memory: "; cin >> storage;
        cout << "Type (0 - SSD, 1 - HDD): "; cin >> kind;
        cout << "Price: "; cin >> price;
        cout << "Stock: "; cin >> stock;
        this->addElement(new Storage(id, name, price, brand, storage, kind), stock);
    }
    else if (type == "MOBO")
    {
        int id, stock;
        string name, brand, aux, format, platform;
        float price;
        cout << "ID: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "Brand: "; cin >> brand;
        cout << "Platform: "; cin >> platform;
        cout << "Form factor: "; cin >> format;
        cout << "Price: "; cin >> price;
        cout << "Stock: "; cin >> stock;
        this->addElement(new MOBO(id, name, price, brand, platform, format), stock);
    }
    else if (type == "Case")
    {
        int id, stock;
        string name, brand, aux, format;
        float price;
        cout << "ID: "; cin >> id;
        cout << "Name: "; cin >> name;
        cout << "Brand: "; cin >> brand;
        cout << "Form factor: "; cin >> format;
        cout << "Price: "; cin >> price;
        cout << "Stock: "; cin >> stock;
        this->addElement(new Case(id, name, price, brand, format), stock);
    }
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
	try {
		this->controller.init();
	}
	catch (int err_c)
	{
		cout << controller.errorHandle(err_c) << endl;
	}
	cout << "Welcome to " << this->controller.getShopName() << endl;
	while (true)
	{
		cout << "1. View the inventory\n";
		cout << "2. Add an item to the inventory\n";
		cout << "0. Exit\n";
		int opt;
		try {
			if (!(cin >> opt))
			{
				cin.clear();
				cin.ignore(10000, '\n');
				throw(3);
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
					this->controller.cleanUp();
					exit(0);
					break;
				default:
					cout << "Wrong option!\n";
					break;
				}
			}
		}
		catch (int err_code)
		{
			cout << controller.errorHandle(err_code) << endl;
		}
		this->pause();
		this->clear();
	}
}

void CLIApp::addElement(Item* x, int stock)
{
    this->controller.getShop().addElem(x, stock);
}
