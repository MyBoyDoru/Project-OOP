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
	return "Unhandled error - please contact the developer of this app";
	this->errCode = -1;
	in.close();
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

string CLIController::logic()
{
	if (this->errCode != -1)
		return "";
	stringstream buff;
	switch (this->tempUserInput)
	{
	case 1:
		buff << "";
		for (int i = 0; i < this->controlledShop.getSz(); i++)
		{
			string aux = this->controlledShop.get(i, this->errCode).first->toString();
			if (this->errCode != -1)
				break;
			buff << aux << " - " << this->controlledShop.get(i, this->errCode).second << " left in stock\n";
		}
		break;
	case 2:
	{
		msgSend("Component setup\n");
		msgSend("Choose from : CPU, GPU, RAM, PSU, Case, MOBO, Storage\n");
		string type_;
		inputGet<string>(type_);
		if (type_ == "CPU")
		{
			int id, coreCount;
			string name, brand;
			float price, frequency;
			msgSend("ID: ");
			inputGet<int>(id);
			msgSend("Brand: ");
			inputGet<string>(brand);
			msgSend("Name: ");
			inputGetLine<string>(name);
			msgSend("Core count: ");
			inputGet<int>(coreCount);
			msgSend("Frequency: ");
			inputGet<float>(frequency);
			msgSend("Price: ");
			inputGet<float>(price);
			CPU c(id, name, price, brand, coreCount, frequency);
			msgSend(c.toString());
		}
		else if (type_ == "GPU")
		{

		}
		else
		{
			this->errCode = 6;
		}
		break;
	}
	case 0:
		exit(0);
		break;
	}
	if (this->errCode != -1)
		return "";
	return buff.str();
}