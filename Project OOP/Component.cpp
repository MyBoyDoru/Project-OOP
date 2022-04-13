#include "Component.h"

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
