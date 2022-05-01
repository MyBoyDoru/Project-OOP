#include <iostream>
#include <string>

/// Helper function to print out some output
/// @param [in] x String containing the output to be printed
void CLIPrint(string x)
{
    std::cout<<x;
}

/// Helper function to get some input
/// @param [out] x The type of this parameter is given by the TElem template. This parameter will contain the input
/// @return The parameter x
template <typename TElem>
TElem CLIInput(TElem& x)
{
    std::cin>>x;
    return x;
}

/// Helper function to get a sentence
/// @param [out] x String containing the sentence
/// @return The parameter x
string CLIGetLine(string& x)
{
    std::getline(std::cin, x);
    std::cin.ignore(10000, '\n');
    return x;
}