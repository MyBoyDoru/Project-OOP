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
    int aux_sz = x.getSz(), err_c = -1;
    for(int i = 0; i < aux_sz; i++)
    {
        out<< x.get(i,err_c).first->getType()<< " " << x.get(i,err_c).first->toString() << " " << x.get(i,err_c).second<<"\n";
    }
    out.close();
}