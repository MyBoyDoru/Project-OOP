#include "CLIApp.h"
#include "CLIController.h"
#include "Shop.h"

int main()
{
	CLIApp app = CLIApp(CLIController(Shop("DenisTechs"), "test.csv"));
	app.Start();
	return 0;
}