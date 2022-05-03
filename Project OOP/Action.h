#pragma once
#include <string>

using std::string;

class Action
{
	/// @class Action
	/// This class will be responsible for remembering actions took before
public:
	Action();
	virtual string getType() { return "DEF_ACTION"; }
};

class ActionAdd : public Action
{
	ActionAdd();
	string getType() { return "ADD_ACTION"; }
private:

};

