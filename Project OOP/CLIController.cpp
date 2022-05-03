#include "CLIController.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using std::getline;
using std::stringstream;

CLIController::CLIController()
{
	this->controlledShop = Shop();
	this->tempUserInput = -1;
}

CLIController::CLIController(const Shop& shop)
{
	this->controlledShop = shop;
	this->tempUserInput = -1;
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

void CLIController::setUserInput(int opt)
{
	if (opt < 0 || opt > 2)
	{
		this->tempUserInput = -1;
		throw(5);
	}
	this->tempUserInput = opt;
}


string CLIController::getAllStr()
{
	stringstream buff;
	buff << "";
	for (int i = 0; i < this->controlledShop.getSz(); i++)
	{
		string aux = this->controlledShop.get(i).first->toString();
		buff << aux << " - " << this->controlledShop.get(i).second << " left in stock\n";
	}
	return buff.str();
}
