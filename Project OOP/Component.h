#pragma once
#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::cout;

class Item
{
public:
	// default constructor
	Item();
	Item(int id, string name, float price);
	//getters
	int getId() const { return this->id; }

	virtual string toString();
	
	//operators
	friend bool operator==(const Item a, const Item b);

	friend istream& operator>>(istream& in, Item& c);

protected:
	// id of the component
	int id;
	// name of the component
	string name;
	// price of the component
	float price;
};

class CPU : public Item
{
public:
	// default constructor for the CPU class
	CPU();
	// alternate constructor for the CPU class
	CPU(int ,string, float, string, int, float);
	string toString();
private:
	// number of cores
	int coreCount;
	// default frequency
	float frequency;
	// self-explanatory
	string brand;

};