//
//  CSVWatchlist.cpp
//  Assignment5-6
//
//  Created by Alex Resiga on 03/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "CSVWatchlist.hpp"

#include <fstream>


using namespace std;

void CSVWatchlist::writeToFile(vector<Movie> m) const
{
    ofstream f("a.csv");
    
    for (auto mu : m)
        f << mu;
    
    f.close();
}

void CSVWatchlist::displayWatchList(vector<Movie> m) const
{
    writeToFile(m);
    system("open /Applications/TextEdit.app/a.csv");
}
