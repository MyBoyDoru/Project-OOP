#include "CLIApp.h"
#include "Controller.h"
#include "Shop.h"

int main()
{
	vector<pair<Item*, int>> a;
	a.push_back(make_pair(new Item(1, "GPU", 599.99),3));
	a.push_back(make_pair(new CPU(2, "Core I5-7400", 399.99,"Intel",4,4.20), 10));
	a.push_back(make_pair(new Item(3, "PSU", 99.99),7));
	CLIApp app(Controller(Shop("DenisTechs",a)));
	app.Start();
	return 0;
}