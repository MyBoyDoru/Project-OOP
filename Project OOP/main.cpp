#include "CLIApp.h"
#include "CLIController.h"
#include "Shop.h"

int main()
{
	vector<pair<Component, int>> a;
	a.push_back(make_pair(Component(1, "GPU", 599.99),3));
	a.push_back(make_pair(Component(2, "CPU", 399.99),10));
	a.push_back(make_pair(Component(3, "PSU", 99.99),7));
	CLIApp app(CLIController(Shop("DenisTechs",a)));
	app.Start();
	return 0;
}