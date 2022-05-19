#pragma once
#include "Item.h"
#include <stack>
#include <string>


using std::stack;
using std::string;
using std::pair;

class CLIController;

class Action
{
public:
	virtual void executeUndo(CLIController* controller) { return; }
	virtual void executeRedo(CLIController* controller) { return; }
};

class ActionAdd : public Action
{
public:
	ActionAdd(pair<Item*, int> item);
	~ActionAdd();
	void executeUndo(CLIController* controller);
	void executeRedo(CLIController* controller);
private:
	pair<Item*, int> addedItem;
};

class ActionRemove : public Action
{
public:
	ActionRemove(pair<Item*, int> item);
	~ActionRemove();
	void executeUndo(CLIController* controller);
	void executeRedo(CLIController* controller);
private:
	pair<Item*, int> removedItem;
};

class ActionManager
{
public:
	ActionManager();
	~ActionManager();
	void addAction(Action* action);
	void undo(CLIController* controller);
	void redo(CLIController* controller);
private:
	stack<Action*> undoStack;
	stack<Action*> redoStack;
};

