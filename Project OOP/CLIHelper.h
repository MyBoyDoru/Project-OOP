#ifndef CLIHELPER_H
#define CLIHELPER_H
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;

void msgSend(string s);

template <typename TElem>
void inputGet(TElem& x)
{
	cin >> x;
}

template<typename TElem>
void inputGetLine(TElem& x)
{
	getline(cin, x);
}
#endif