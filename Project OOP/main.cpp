#include "CLIApp.h"
#include "CLIController.h"
#include "Shop.h"
#include "TestUnit.h"
#define TESTING 1

int main()
{
#if TESTING < 1
	CLIApp app = CLIApp(CLIController(Shop("DenisTechs"), "test.csv"));
	app.Start();
#else
	TestUnit test(2);
	test.runTests();
#endif
	return 0;
}