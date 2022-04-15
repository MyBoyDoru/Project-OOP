#pragma once
#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::cout;

class Component
{
public:
	// default constructor
	Component();
	Component(int id, string name, float price);
	//getters
	int getId() const { return this->id; }

	string toString();
	
	//operators
	friend bool operator==(const Component a, const Component b);

	friend istream& operator>>(istream& in, Component& c);

private:
	// id of the component
	int id;
	// name of the component
	string name;
	// price of the component
	float price;
};

