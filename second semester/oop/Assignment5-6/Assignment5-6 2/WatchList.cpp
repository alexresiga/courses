//
//  WatchList.cpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "WatchList.hpp"
#include <iostream>
#include <fstream>
using namespace std;

WatchList::WatchList()
{
    this->current = 0;
}


void WatchList::addToWatchlist(const Movie &movie)
{

    for (int i = 0 ;i < this->movies.size(); ++i)
    {
        Movie m = this->movies[i];
        if (movie.getTitle() == m.getTitle() and movie.getYear() == m.getYear())
        {cout<<"\nExisting movie in watchlist\n";return;}
    }
    this->movies.push_back(movie);

}

Movie WatchList::deleteFromWatchlist(const std::string &title, const int &year)
{
    
    for (int i = 0 ;i < this->movies.size(); ++i)
    {
        Movie m = this->movies[i];
        if (m.getTitle() ==title and m.getYear() == year)
        {
            string ans;
            cout<<"Did you like this movie?";
            getline(cin, ans);
            if (ans == "yes")
                m.increaseLikes();
            this->movies.erase(this->movies.begin() +i);
            return m;
            
        }

    }
    cout<<"\nNon existing movie in watchlist\n";
    return Movie();
}

Movie WatchList::getCurrentMovie()
{
    if (this->current == this->movies.size())
        this->current = 0;
    
    return this->movies[this->current];
}

void WatchList::play(const int& storage)
{
    
    if (this->movies.size() == 0)
        return;
    this->current = 0;
    Movie currentMovie = this->getCurrentMovie();
    currentMovie.play();
     
}

void WatchList::next()
{
    if (this->movies.size() == 0) {
        return;
    }
    this->current++;
    Movie currentMovie = this->getCurrentMovie();
    currentMovie.play();
}

bool WatchList::isEmpty()
{
    return this->movies.size() == 0;
}
