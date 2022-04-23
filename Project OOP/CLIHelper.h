#include <iostream>
#include <string>

void CLIPrint(string x)
{
    std::cout<<x;
}

template <typename TElem>
TElem CLIInput(TElem& x)
{
    std::cin>>x;
    return x;
}

string CLIGetLine(string& x)
{
    std::getline(std::cin, x);
    std::cin.ignore(10000, '\n');
    return x;
}