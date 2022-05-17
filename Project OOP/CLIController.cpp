#include "CLIController.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using std::getline;
using std::stringstream;

CLIController::CLIController() : fileHandler("temp.csv")
{
	this->controlledShop = Shop();
}

CLIController::CLIController(const Shop& shop, string handler) : fileHandler(handler)
{
	this->controlledShop = shop;
}
CLIController::~CLIController()
{
	while (this->undoStack.size() > 0)
	{
		delete this->undoStack.top();
		this->undoStack.pop();
	}
	while (this->redoStack.size() > 0)
	{
		delete this->redoStack.top();
		this->redoStack.pop();
	}
}

string CLIController::errorHandle(int errCode)
{
	if (errCode < 0)
		return "";
	int aux;
	ifstream in("err_codes.txt");
	while (in >> aux)
	{
		string aux1;
		getline(in, aux1);
		aux1[0] = '\0';
		if (aux == errCode)
		{
			aux1 += " - error code: " + to_string(errCode);
			errCode = -1;
			return aux1;
		}
	}
    in.close();
	return "Unhandled error - please contact the developer of this app";
}

string CLIController::getAllStr()
{
	stringstream buff;
	buff << "";
	for (int i = 0; i < this->controlledShop.getSz(); i++)
	{
		string aux = this->controlledShop[i].first->toString();
		buff << aux << " - " << this->controlledShop[i].second << " left in stock\n";
	}
	return buff.str();
}

void CLIController::init()
{
	this->fileHandler.load(this->controlledShop);
	return;
}

void CLIController::cleanUp()
{
	this->fileHandler.save(this->controlledShop);
}

void CLIController::addElem(Item* x, int s)
{
	this->controlledShop.addElem(x, s);
}

void CLIController::removeElem(int id)
{
	if (this->controlledShop.getElemById(id) != nullptr)
	{
		this->controlledShop.remElem(id);
		return;
	}
	throw(8);
}

Item* CLIController::get(int id)
{
	if (this->controlledShop.getElemById(id) != nullptr)
	{
		return this->controlledShop.getElemById(id);
	}
	throw(4);
}

void CLIController::modify(pair<Item*, int> x, int id)
{
	for (int i = 0; i <= this->controlledShop.getSz(); i++)
	{
		if (this->controlledShop[i].first->getId() == id)
		{
			this->controlledShop[i] = x;
			return;
		}
	}
}

void CLIController::undo()
{
	if (this->undoStack.size() > 0)
	{
		this->undoStack.top()->executeUndo(this);
		this->redoStack.push(this->undoStack.top());
		this->undoStack.pop();
	}
}

void CLIController::addAction(Action* action)
{
	this->redoStack = stack<Action*>();
	this->undoStack.push(action);
}

string CLIController::filterType(string type)
{
	FilterType a(type);
	vector<pair<Item*, int>> arr = this->controlledShop.getList();
	vector<pair<Item*, int>> rez = a.filter(arr);
	stringstream buff("");
	for (int i = 0; i < rez.size(); i++)
	{
		buff << rez[i].first->toString() << " - stock " << rez[i].second<<"\n";
	}
	return buff.str();
}


string CLIController::filterPrice(float price)
{
	FilterPrice a(price);
	vector<pair<Item*, int>> arr = this->controlledShop.getList();
	vector<pair<Item*, int>> rez = a.filter(arr);
	stringstream buff("");
	for (int i = 0; i < rez.size(); i++)
	{
		buff << rez[i].first->toString() << " - stock " << rez[i].second << "\n";
	}
	return buff.str();
}

string CLIController::filterBoth(string type, float price)
{
	FilterType* A = new FilterType(type);
	FilterPrice* B = new FilterPrice(price);
	FilterAnd a(A,B);
	vector<pair<Item*, int>> arr = this->controlledShop.getList();
	vector<pair<Item*, int>> rez = a.filter(arr);
	stringstream buff("");
	for (int i = 0; i < rez.size(); i++)
	{
		buff << rez[i].first->toString() << " - stock " << rez[i].second << "\n";
	}
	return buff.str();
}
