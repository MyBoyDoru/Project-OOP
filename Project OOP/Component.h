#pragma once
#include <string>

using std::string;
class Component
{
	// default constructor
	Component(int id, string name, float price);
	int getId() const { return this->id; }
	friend bool operator==(const Component a, const Component b);
private:
	// id of the component
	int id;
	// name of the component
	string name;
	// price of the component
	float price;
};

