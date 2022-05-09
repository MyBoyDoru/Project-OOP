#include "ActionManager.h"

void ActionManager::addAction(Shop shop)
{
	this->actionStack.push(shop);
	this->wasUndo = false;
}


// TODO: FIX THIS ASAP!!!
Shop ActionManager::undo()
{
	if (this->actionStack.empty())
		throw(8);
	this->wasUndo = true;
	this->actionStack.pop();
	Shop rez = this->actionStack.top();
	return rez;
}
