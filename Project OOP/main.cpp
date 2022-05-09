#include "CLIApp.h"
#include "CLIController.h"
#include "Shop.h"

int main()
{
	/*vector<pair<Item*, int>> a;
	a.push_back(make_pair(new GPU(1, "RTX 3090ti", 1099.99, "Nvidia", 1860, 24), 3));
	a.push_back(make_pair(new CPU(2, "Core I5-7400", 399.99,"Intel",4,4.20), 10));
	a.push_back(make_pair(new RAM(3, "Vengeance RGB PRO", 199.99, "Corsair", 3200, 32, 2), 7));
	a.push_back(make_pair(new PSU(4, "RM650", 69.99, "Corsair", 650, "80 Gold"), 4));
	a.push_back(make_pair(new Storage(5, "EVO950",150,"Samsung",1000,1), 20));
	a.push_back(make_pair(new MOBO(6, "Z170 PRO GAMING", 180, "Asus", "Intel", "ATX"), 3));
	a.push_back(make_pair(new Case(7, "H700i", 149.99, "NZXT", "ATX"), 5));*/
	CLIApp app = CLIApp(CLIController(Shop("DenisTechs"), "test.csv"));
	app.Start();
	return 0;
}