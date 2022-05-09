#pragma once
#include "Shop.h"
#include <string>
#include <stack>

using std::string;
using std::stack;

class ActionManager
{
public:
	ActionManager() { this->wasUndo = false; }
	/// <summary>
	/// Adds a new shop state to the action stack
	/// </summary>
	/// <param name="shop">Shop state to be added</param>
	void addAction(Shop shop);
	/// <summary>
	/// Function to undo some changes to the inventory
	/// </summary>
	/// <returns>the previous state of the shop</returns>
	Shop undo();
	/// Doesnt work at all
	Shop redo();
private:
	stack<Shop> actionStack;
	bool wasUndo;
};
