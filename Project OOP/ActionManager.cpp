#include "ActionManager.h"

void ActionManager::addAction(Shop shop)
{
	this->actionStack.push(shop);
	this->wasUndo = false;
}


// TODO: FIX THIS ASAP!!!
Shop ActionManager::undo()
{
	this->wasUndo = true;
	Shop rez = this->actionStack.top();
	this->actionStack.pop();
	return rez;
}
