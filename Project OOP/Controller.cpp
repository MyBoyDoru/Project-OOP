#include "Controller.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using std::getline;
using std::stringstream;

Controller::Controller()
{
	this->controlledShop = Shop();
	this->tempUserInput = -1;
	this->errCode = -1;
}

Controller::Controller(const Shop& shop)
{
	this->controlledShop = shop;
	this->tempUserInput = -1;
	this->errCode = -1;
}

string Controller::errorHandle()
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
			this->errCode = -1;
			return aux1;
		}
	}
	return "Unhandled error - please contact the developer of this app";
	this->errCode = -1;
	in.close();
}

void Controller::setUserInput(int opt)
{
	if (opt < 0 || opt > 2)
	{
		this->errCode = 4;
		this->tempUserInput = -1;
		return;
	}
	this->tempUserInput = opt;
}

string Controller::logic()
{
	stringstream buff;
	switch (this->tempUserInput)
	{
	case 1:
		buff << "";
		for (int i = 0; i < this->controlledShop.getSz(); i++)
		{
			string aux = this->controlledShop.get(i, this->errCode).first.toString();
			if (this->errCode != -1)
				break;
			buff << aux << "\n";
		}
		break;
	case 2:

	case 0:
		exit(0);
		break;
	}
	if (this->errCode != -1)
		return "";
	return buff.str();
}