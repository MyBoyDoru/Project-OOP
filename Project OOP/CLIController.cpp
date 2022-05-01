#include "CLIController.h"
#include "CLIHelper.h"
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
		this->errCode = 4;
		this->tempUserInput = -1;
		return;
	}
	this->tempUserInput = opt;
}

string CLIController::logic()
{
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
			string x;
			CLIPrint("Enter the type of the item. You can choose from: CPU, GPU, RAM, PSU, MOBO, Storage, CASE\n");
			CLIInput(x);
			if(x == "CPU")
			{
				string name, brand;
				int coreCount, id, stock;
				float price, frequency;
				CLIPrint("ID: ");
				CLIInput(id);
				CLIPrint("Brand: ");
				CLIGetLine(brand);
				CLIPrint("Name: ");
				CLIGetLine(name);
				CLIPrint("Core count: ");
				CLIInput(coreCount);
				CLIPrint("Frequency: ");
				CLIInput(frequency);
				CLIPrint("Price: ");
				CLIInput(price);
				CLIPrint("Stock: ");
				CLIInput(stock);
				CPU* aux = new CPU(id, name, price, brand, coreCount, frequency);
				this->controlledShop.addElem(aux , stock, this->errCode);
			}
			else
			{
				this->errCode = 6;
				return "";
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