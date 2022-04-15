#include "Component.h"
#include <sstream>
#include <iomanip>

using std::stringstream;
using std::setprecision;
using std::fixed;

Component::Component()
{
	this->id = -1;
	this->name = "";
	this->price = -1;
}

Component::Component(int id, string name, float price)
{
	this->id = id;
	this->name = name;
	this->price = price;
}

bool operator==(const Component a, const Component b)
{
	return a.id == b.id;
}

istream& operator>>(istream& in, Component& c)
{
	cout << "ID of the component: ";
	in >> c.id;
	cout << "Name of the component: ";
	in >> c.name;
	cout << "Price of the component: ";
	in >> c.price;
	return in;
}

string Component::toString()
{
	stringstream buff;
	buff << this->id << " - " << this->name << ", " << fixed << setprecision(2) << this->price << "$";
	return buff.str();
}