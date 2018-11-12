//
//  HTMLWatchlist.cpp
//  Assignment5-6
//
//  Created by Alex Resiga on 03/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "HTMLWatchlist.hpp"

#include <fstream>


using namespace std;

void HTMLWatchlist::writeToFile(vector<Movie> a) const
{
    ofstream f("index.html");
    f<<"<!DOCTYPE html><html><head><title>Watchlist</title></head> <body><table border='1'><thead><td>Title</td><td>Genre</td><td>Year</td><td>Likes</td><td>Trailer</td></thead><tbody>";
    for (auto m : a)
        f << "<tr><td>"<<m.getTitle()<<"</td><td>"<<m.getGenre()<<"</td><td>"<<m.getLikes()<<"</td><td>"<<m.getYear()<<"</td><td><a href='"<<m.getTrailer()<<"' target='_blank'> Link </a></td></tr>";
    f<<"</tbody></table></body></html>";
    f.close();
}

void HTMLWatchlist::displayWatchList(vector<Movie> m) const
{
    this->writeToFile(m);
    system("open index.html");
}
