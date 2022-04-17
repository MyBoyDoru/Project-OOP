#pragma once
#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::cout;

// base class for every item in the inventory
class Item
{
public:
	// default constructor
	Item();
	Item(int id, string name, float price);
	//getters
	int getId() const { return this->id; }
	virtual string getType() const { return "ITEM"; };
	virtual string toString();
	
	//operators
	friend bool operator==(const Item a, const Item b);

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
	CPU(int id,string name, float price, string brand, int coreCount, float frequency);
	string toString();
	string getType() const { return "CPU"; };
private:
	// number of cores
	int coreCount;
	// default frequency in gHz
	float frequency;
	// self-explanatory
	string brand;

};

class GPU : public Item
{
public:
	// default constructor
	GPU();
	// alternate constructor
	GPU(int id, string name, float price, string brand, int frequency, int DRAM);
	string toString();
	string getType() const { return "GPU"; };
private:
	// frequency of the GPU in hz, memory of the GPU in GB
	int frequency, DRAM;
	// self-explanatory
	string brand;
};

class RAM : public Item
{
public:
	// default constructor
	RAM();
	// alternate constructor
	RAM(int id, string name, float price, string brand, int frequency, int RAM, int modules);
	string toString();
	string getType() const { return "RAM"; };
private:
	// frequency of the RAM in hz, memory of the RAM in GB
	int frequency, RAM_, modules;
	// self-explanatory
	string brand;
};

class PSU : public Item
{
public:
	// default constructor
	PSU();
	// alternate constructor
	PSU(int id, string name, float price, string brand, int wattage, string rating);
	string toString();
	string getType() const { return "PSU"; };
private:
	// max operational wattage
	int wattage;
	// rating of the psu, e.g. "80 bronze" or "90 gold"
	string rating;
	// do I have to say it every time? I wont comment from now on
	string brand;
};

class Storage : public Item
{
public:
	Storage();
	Storage(int id, string name, float price, string brand, int size, int type);
	string toString();
	string getType() const { return "Storage"; };
private:
	string brand;
	// size of the hdd/ssd in GB
	int size;
	// type of the storage, 0 for hdd, 1 for ssd
	int type;
};

class MOBO : public Item
{
public:
	MOBO();
	MOBO(int id, string name, float price, string brand, string platform, string formFactor);
	string toString();
	string getType() const { return "MOBO"; };
private:
	string brand;
	// if its either Intel or Amd
	string platform;
	// the size of the motherboard
	string formFactor;
};

class Case : public Item
{
public:
	Case();
	Case(int id, string name, float price, string brand, string formFactor);
	string toString();
	string getType() const { return "Case"; }
private:
	string brand;
	// the size of the motherboard it can house
	string formFactor;
};