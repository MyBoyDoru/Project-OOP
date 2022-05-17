#pragma once
#include "Component.h"
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
protected:
	virtual string getType() { return "DEFAULT_ACTION"; }
};

class ActionAdd : public Action
{
public:
	ActionAdd(pair<Item*, int> item);
	~ActionAdd();
	void executeUndo(CLIController* controller);
	void executeRedo(CLIController* controller);
private:
	string getType() { return "ADD_ACTION"; }
	pair<Item*, int> addedItem;
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

