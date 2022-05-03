#include "Shop.h"

Shop::Shop()
{
	this->name = "";
	this->sz = 0;
}

Shop::Shop(string name)
{
	this->name = name;
	this->sz = 0;
}

Shop::Shop(string name, vector<pair<Item*, int>> vec)
{
	this->sell = vec;
	this->sz = this->sell.size();
	this->name = name;
}

Shop::Shop(const Shop& other)
{
	this->name = other.name;
	this->sz = other.sz;
	this->sell = other.sell;
}

int Shop::internalSearch(Item c)
{
	int iter = 0;
	for (auto& it : this->sell)
	{
		if (*it.first == c)
			return iter;
		iter++;
	}
	return -1;
}

pair<Item*, int> Shop::get(int x)
{
	if (!(x >= 0 && x <= sz))
	{
		throw(4);
	}
	return this->sell[x];
}

Shop Shop::operator=(const Shop other)
{
	this->name = other.name;
	this->sz = other.sz;
	this->sell = other.sell;
	return *this;
}

void Shop::addElem(Item* c, int stock)
{
	// pre
	// check stock for positive
	if (stock < 0)
	{
		throw(1);
	}
	// search and check if c exists
	if (this->internalSearch(*c) != -1)
	{
		throw(2);
	}
	this->sell.push_back(make_pair(c,stock));
}

