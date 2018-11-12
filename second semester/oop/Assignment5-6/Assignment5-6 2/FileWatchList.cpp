//
//  FileWatchList.cpp
//  Assignment5-6
//
//  Created by Alex Resiga on 02/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "FileWatchList.hpp"
#include <fstream>

using namespace std;

FileWatchList::FileWatchList() : WatchList{}, filename{""}
{
    
}

void FileWatchList::setFilename(const std::string &filename)
{
    this->filename = filename;
}


