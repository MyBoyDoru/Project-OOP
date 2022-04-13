#include "Controller.h"
#include <fstream>
#define MAX_ERR_CODES 2

using std::ifstream;
using std::getline;

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
	if (this->errCode < 0 or this->errCode > MAX_ERR_CODES)
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
			return aux1;
		}
	}
	return "Unhandled error - please contact the developer of this app";
	in.close();
}

void Controller::setUserInput(int opt)
{

}