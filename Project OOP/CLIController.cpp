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
