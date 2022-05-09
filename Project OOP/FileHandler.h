//
// Created by Denis Leonte on 29/04/2022.
//

#ifndef PROJECT_OOP_FILEHANDLER_H
#define PROJECT_OOP_FILEHANDLER_H
#include <string>
#include <fstream>
#include "Shop.h"

using std::string;
using std::ifstream;
using std::ofstream;

class FileHandler {
    /// @class FileHandler
    /// Handles files, saves and loads.
public:
    FileHandler();
    /// Constructor
    /// @param [in] path Path to the handled file
    FileHandler(string path);
    void save(Shop x);
    void load(Shop& x);

private:
    string filePath;
};


#endif //PROJECT_OOP_FILEHANDLER_H
