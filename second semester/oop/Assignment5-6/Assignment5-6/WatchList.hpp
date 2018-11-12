//
//  WatchList.hpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include <stdio.h>
#include "DynamicVector.hpp"
#include "Movie.h"
#include <vector>

class WatchList
{
public:
    vector<Movie> movies;
    int current;
    
public:
    WatchList();
    
    vector<Movie> getMovies() {return this->movies;}
    //add a movie to the watchlist
    void addToWatchlist(const Movie& movie);
    
    Movie deleteFromWatchlist(const string& title, const int& year);
    
    //return the currently playing movie
    Movie getCurrentMovie();
        
    //starts the watchlist
    void play(const int& storage);
    
    //play the next movie trailer
    void next();
    
    //check if the watchlist is empty
    bool isEmpty();

};
