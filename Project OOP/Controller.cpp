#include "Controller.h"

Controller::Controller()
{
	this->controlledShop = Shop();
}

Controller::Controller(const Shop& shop)
{
	this->controlledShop = shop;
}
