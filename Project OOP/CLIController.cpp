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
	this->errCode = -1;
}

CLIController::CLIController(const Shop& shop)
{
	this->controlledShop = shop;
	this->tempUserInput = -1;
	this->errCode = -1;
}

string CLIController::errorHandle()
{
	if (this->errCode < 0)
		return "";
	int aux;
	ifstream in("err_codes.txt");
	while (in >> aux)
	{
		string aux1;
		getline(in, aux1);
		aux1[0] = '\0';
		if (aux == this->errCode)
		{
			aux1 += " - error code: " + to_string(this->errCode);
			this->errCode = -1;
			return aux1;
		}
	}
    this->errCode = -1;
    in.close();
	return "Unhandled error - please contact the developer of this app";
}

void CLIController::setUserInput(int opt)
{
	if (opt < 0 || opt > 2)
	{
		this->errCode = 5;
		this->tempUserInput = -1;
		return;
	}
	this->tempUserInput = opt;
}


string CLIController::getAllStr()
{
	stringstream buff;
	buff << "";
	for (int i = 0; i < this->controlledShop.getSz(); i++)
	{
		string aux = this->controlledShop.get(i, this->errCode).first->toString();
		if (this->errCode != -1)
			break;
		buff << aux << " - " << this->controlledShop.get(i, this->errCode).second << " left in stock\n";
	}
	return buff.str();
}
