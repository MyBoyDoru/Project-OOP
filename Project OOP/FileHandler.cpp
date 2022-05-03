//
// Created by Denis Leonte on 29/04/2022.
//

#include "FileHandler.h"

FileHandler::FileHandler(string path)
{
    this->filePath = path;
}

void FileHandler::save(Shop x)
{
    ofstream out(this->filePath.c_str());
    int aux_sz = x.getSz();
    for(int i = 0; i < aux_sz; i++)
    {
        out<< x.get(i).first->getType()<< " " << x.get(i).first->toString() << " " << x.get(i).second<<"\n";
    }
    out.close();
}