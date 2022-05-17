#pragma once
#include "CLIController.h"
#include <stack>
#include <string>


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
