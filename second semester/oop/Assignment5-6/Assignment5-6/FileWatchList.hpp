//
//  FileWatchList.hpp
//  Assignment5-6
//
//  Created by Alex Resiga on 02/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//
#pragma once
#include "FileWatchList.hpp"
#include "WatchList.hpp"
#include <string>
#include <fstream>

using namespace std;

class FileWatchList: public WatchList
{
protected:
    string filename;
    
public:
    FileWatchList();
    virtual ~FileWatchList() {}
    void setFilename(const string& filename);
    virtual void writeToFile(vector<Movie>) const = 0;
    virtual void displayWatchList(vector<Movie>) const = 0;
};
