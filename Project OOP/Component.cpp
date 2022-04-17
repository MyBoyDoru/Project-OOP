#include "Component.h"
#include <sstream>
#include <iomanip>

using std::stringstream;
using std::setprecision;
using std::fixed;

Item::Item()
{
	this->id = -1;
	this->name = "";
	this->price = -1;
}

Item::Item(int id, string name, float price)
{
	this->id = id;
	this->name = name;
	this->price = price;
}

bool operator==(const Item a, const Item b)
{
	return a.id == b.id;
}

istream& operator>>(istream& in, Item& c)
{
	cout << "ID of the component: ";
	in >> c.id;
	cout << "Name of the component: ";
	in >> c.name;
	cout << "Price of the component: ";
	in >> c.price;
	return in;
}

string Item::toString()
{
	stringstream buff;
	buff << this->id << " - " << this->name << ", " << fixed << setprecision(2) << this->price << "$";
	return buff.str();
}

CPU::CPU() : Item()
{
	this->name = "";
	this->id = -1;
	this->price = -1;
	this->coreCount = 0;
	this->frequency = 0;
	this->brand = "";
}

CPU::CPU(int id, string name, float price, string brand, int coreCount, float frequency) : Item(id, name, price)
{
	this->brand = brand;
	this->coreCount = coreCount;
	this->frequency = frequency;
}

string CPU::toString()
{
	stringstream buff;
	buff << this->id << " - " << this->brand << " " << this->name << ", " << this->coreCount;
	buff << " cores, @" << fixed << setprecision(2) << this->frequency << " gHz, " << this->price << "$";
	return buff.str();
}