//
//  CSVWatchlist.hpp
//  Assignment5-6
//
//  Created by Alex Resiga on 03/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include "FileWatchList.hpp"
#include <string>

class CSVWatchlist: public FileWatchList
{
public:
    /*
     Writes the playlist to file.
     Throws: FileException - if it cannot write.
     */
    void writeToFile(vector<Movie>) const override;
    
    /*
     Displays the playlist using Microsof Excel.
     */
    void displayWatchList(vector<Movie>) const override;
};


