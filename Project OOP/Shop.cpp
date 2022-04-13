#include "Shop.h"

Shop::Shop(string name)
{
	this->name = name;
	this->sz = 0;
}

Shop::Shop(const Shop& other)
{
	this->name = other.name;
	this->sz = other.sz;
	this->sell = other.sell;
}

int Shop::internalSearch(Component c)
{
	int iter = 0;
	for (auto& it : this->sell)
	{
		if (it.first == c)
			return iter;
		iter++;
	}
	return -1;
}

void Shop::addElem(Component c, int stock, int& err_c)
{
	err_c = 0;
	// pre
	// check stock for positive
	if (stock < 0)
	{
		err_c = 1;
		return;
	}
	// search and check if c exists
	if (this->internalSearch(c) != -1)
	{
		err_c = 2;
		return;
	}
	this->sell.push_back(make_pair(c,stock));
}

