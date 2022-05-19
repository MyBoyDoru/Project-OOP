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
using std::getline;

string getLine(string& x)
{
    cin >> std::ws;
    getline(cin, x);
    return x;
}

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

CPU* CLIApp::inputCPU()
{
    int id, coreCount;
    float price, frequency;
    string brand, name;
    cout << "ID: "; cin >> id;
    cout << "Brand: "; getLine(brand);
    cout << "Name: "; getLine(name);
    cout << "Core count: "; cin >> coreCount;
    cout << "Frequency: "; cin >> frequency;
    cout << "Price: "; cin >> price;
    return new CPU(id, name, price, brand, coreCount, frequency);
}

GPU* CLIApp::inputGPU()
{
    int id, VRAM, frequency;
    float price;
    string brand, name;
    cout << "ID: "; cin >> id;
    cout << "Brand: "; getLine(brand);
    cout << "Name: "; getLine(name);
    cout << "Frequency: "; cin >> frequency;
    cout << "VRAM: "; cin >> VRAM;
    cout << "Price: "; cin >> price;
    return new GPU(id, name, price, brand, frequency, VRAM);
}

RAM* CLIApp::inputRAM()
{
    int id, DRAM, modules, frequency;
    string name, brand;
    float price;
    cout << "ID: "; cin >> id;
    cout << "Brand: "; getLine(brand);
    cout << "Name: "; getLine(name);
    cout << "Frequency: "; cin >> frequency;
    cout << "DRAM: "; cin >> DRAM;
    cout << "Modules: "; cin >> modules;
    cout << "Price: "; cin >> price;
    return new RAM(id, name, price, brand, frequency, DRAM, modules);
}

PSU* CLIApp::inputPSU()
{
    int id, wattage;
    string name, brand, rating;
    float price;
    cout << "ID: "; cin >> id;
    cout << "Brand: "; getLine(brand);
    cout << "Name: "; getLine(name);
    cout << "Wattage: "; cin >> wattage;
    cout << "Rating: "; getLine(rating);
    cout << "Price: "; cin >> price;
    return new PSU(id, name, price, brand, wattage, rating);
}

Storage* CLIApp::inputStorage()
{
    int id, storage, kind;
    string name, brand;
    float price;
    cout << "ID: "; cin >> id;
    cout << "Brand: "; getLine(brand);
    cout << "Name: "; getLine(name);
    cout << "Memory: "; cin >> storage;
    cout << "Type (0 - SSD, 1 - HDD): "; cin >> kind;
    cout << "Price: "; cin >> price;
    return new Storage(id, name, price, brand, storage, kind);
}

MOBO* CLIApp::inputMOBO()
{
    int id;
    string name, brand, format, platform;
    float price;
    cout << "ID: "; cin >> id;
    cout << "Brand: "; getLine(brand);
    cout << "Name: "; getLine(name);
    cout << "Platform: "; getLine(platform);
    cout << "Form factor: "; getLine(format);
    cout << "Price: "; cin >> price;
    return new MOBO(id, name, price, brand, platform, format);
}

Case* CLIApp::inputCase()
{
    int id, stock;
    string name, brand, format;
    float price;
    cout << "ID: "; cin >> id;
    cout << "Brand: "; getLine(brand);
    cout << "Name: "; getLine(name);
    cout << "Form factor: "; getLine(format);
    cout << "Price: "; cin >> price;
    return new Case(id, name, price, brand, format);
}

void CLIApp::setup()
{
	cout << "Item setup\n";
	cout << "Type of Item(CPU, GPU, RAM, PSU, Storage, MOBO, Case): ";
    string type;
    cin >> type;
    if (type == "CPU")
    {
        int stock;
        CPU* x = this->inputCPU();
        cout << "Stock: "; cin >> stock;
        this->addElement(x, stock);
		this->addAction(new ActionAdd(make_pair(x, stock)));
    }
    else if (type == "GPU")
    {
        int stock;
        GPU* x = this->inputGPU();
        cout << "Stock: "; cin >> stock;
        this->addElement(x, stock);
		this->addAction(new ActionAdd(make_pair(x, stock)));
    }
    else if (type == "RAM")
    {
        int stock;
        RAM* x = this->inputRAM();
        cout << "Stock: "; cin >> stock;
        this->addElement(x, stock);
		this->addAction(new ActionAdd(make_pair(x, stock)));
    }
    else if (type == "PSU")
    {
        int stock;
        PSU* x = this->inputPSU();
        cout << "Stock: "; cin >> stock;
        this->addElement(x, stock);
		this->addAction(new ActionAdd(make_pair(x, stock)));
    }
    else if (type == "Storage")
    {
        int stock;
        Storage* x = this->inputStorage();
        cout << "Stock: "; cin >> stock;
        this->addElement(x, stock);
		this->addAction(new ActionAdd(make_pair(x, stock)));
    }
    else if (type == "MOBO")
    {
        int stock;
        MOBO* x = this->inputMOBO();
        cout << "Stock: "; cin >> stock;
        this->addElement(x, stock);
		this->addAction(new ActionAdd(make_pair(x, stock)));
    }
    else if (type == "Case")
    {
        int stock;
        Case* x = this->inputCase();
        cout << "Stock: "; cin >> stock;
        this->addElement(x, stock);
		this->addAction(new ActionAdd(make_pair(x, stock)));
    }
}

void CLIApp::remove()
{
    int id;
    cout << "Element removal\n";
    cout << "ID of the element to remove: "; cin >> id;
    this->controller.removeElem(id);
}

void CLIApp::modify()
{
	int id;
	cout << "Item modify\n";
	cout << "ID of the item to modify: "; cin >> id;
	Item* y = this->controller.get(id);
    cout << y->toString() << endl;
    string type = y->getType();
    if (type == "CPU")
    {
        int stock;
        CPU* x = this->inputCPU();
        cout << "Stock: "; cin >> stock;
        this->controller.modify(make_pair(x,stock), id);
    }
    else if (type == "GPU")
    {
        int stock;
        GPU* x = this->inputGPU();
        cout << "Stock: "; cin >> stock;
        this->controller.modify(make_pair(x, stock), id);
    }
    else if (type == "RAM")
    {
        int stock;
        RAM* x = this->inputRAM();
        cout << "Stock: "; cin >> stock;
        this->controller.modify(make_pair(x, stock), id);
    }
    else if (type == "PSU")
    {
        int stock;
        PSU* x = this->inputPSU();
        cout << "Stock: "; cin >> stock;
        this->controller.modify(make_pair(x, stock), id);
    }
    else if (type == "Storage")
    {
        int stock;
        Storage* x = this->inputStorage();
        cout << "Stock: "; cin >> stock;
        this->controller.modify(make_pair(x, stock), id);
    }
    else if (type == "MOBO")
    {
        int stock;
        MOBO* x = this->inputMOBO();
        cout << "Stock: "; cin >> stock;
        this->controller.modify(make_pair(x, stock), id);
    }
    else if (type == "Case")
    {
        int stock;
        Case* x = this->inputCase();
        cout << "Stock: "; cin >> stock;
        this->controller.modify(make_pair(x, stock), id);
    }
}

void CLIApp::filter()
{
    int opt;
    cout << "Filtering menu\n";
    cout << "Select the type of filter\n";
    cout << "1. By type\n2. By price\n3. Both\n";
    cin >> opt;
    switch (opt)
    {
    case 1:
    {
        string type;
        cout << "Type: "; cin >> type;
        cout << this->controller.filterType(type);
        break;
    }
    case 2:
    {
        float price;
        cout << "Price: "; cin >> price;
        cout << this->controller.filterPrice(price);
        break;
    }
    case 3:
    {
        string type;
        float price;
        cout << "Type: "; cin >> type;
        cout << "Price: "; cin >> price;
        cout << this->controller.filterBoth(type, price);
        break;
    }
    default:
        break;
    }
}

void CLIApp::undo()
{
	this->manager.undo(&this->controller);
    cout << "Action undone!\n";
}

void CLIApp::redo()
{
    this->manager.redo(&this->controller);
    cout << "Action redone!\n";
}

void CLIApp::addAction(Action* action)
{
	this->manager.addAction(action);
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
        cout << "3. Remove an item from the inventory\n";
        cout << "4. Modify an item from the inventory\n";
        cout << "5. Filter the inventory\n";
        cout << "6. Undo\n";
        cout << "7. Redo\n";
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
                    break;
                case 3:
                    this->remove();
                    break;
                case 4:
                    this->modify();
                    break;
                case 5:
                    this->filter();
                    break;
                case 6:
                    this->undo();
                    break;
                case 7:
                    this->redo();
                    break;
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
    this->controller.addElem(x, stock);
}
