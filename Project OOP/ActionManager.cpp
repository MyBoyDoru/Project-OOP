#include "ActionManager.h"
#include "CLIController.h"

ActionManager::ActionManager()
{
	return;
}

ActionManager::~ActionManager()
{
	
}

void ActionManager::addAction(Action* action)
{
	this->redoStack = stack<Action*>();
	this->undoStack.push(action);
}

ActionAdd::ActionAdd(pair<Item*,int> item) : Action()
{
	this->addedItem = item;
}

ActionAdd::~ActionAdd()
{
	delete this->addedItem.first;
}

void ActionAdd::executeUndo(CLIController* controller)
{
	controller->removeElem(this->addedItem.first->getId());
}

void ActionAdd::executeRedo(CLIController* controller)
{
	controller->addElem(this->addedItem.first, this->addedItem.second);
}

void ActionManager::undo(CLIController* controller)
{
	if (this->undoStack.size() > 0)
	{
		this->undoStack.top()->executeUndo(controller);
		this->redoStack.push(this->undoStack.top());
		this->undoStack.pop();
	}
}


void ActionManager::redo(CLIController* controller)
{
	if (this->redoStack.size() > 0)
	{
		this->redoStack.top()->executeRedo(controller);
		this->undoStack.push(this->redoStack.top());
		this->redoStack.pop();
	}
}
