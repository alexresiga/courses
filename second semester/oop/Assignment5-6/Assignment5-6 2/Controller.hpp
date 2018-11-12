//
//  Controller.hpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include <string>
#include "Repository.hpp"
#include "WatchList.hpp"
#include "FileWatchList.hpp"
#include "CSVWatchlist.hpp"
#include "HTMLWatchlist.hpp"
using namespace std;

class Controller
{
private:
    Repository repo;
   
public:
    WatchList watchlist;
    int storage;
    FileWatchList* filewatchlist;
    
public:
    Controller(const Repository& r, FileWatchList* f): repo{r}, filewatchlist{f} {}
    
    Repository getRepo() const {return repo;}
    WatchList getWatchList() const {return watchlist;}
    
    void addMovieToRepo(const string& title, const string& genre, const unsigned int& year, const unsigned int& likes, const string& trailer);
    
    void removeMovieFromRepo(const string& title, const unsigned int &year);
    
    void updateMovieRepo(const string& title, const string& genre, const unsigned int& year, const unsigned int& likes, const string& trailer);
    
    void addMovieByGenre(const string& genre);
    
    WatchList& getWatchlist() {return this->watchlist;}
    
    void addMovieToWatchList(const Movie& movie);
    
    void deleteMovieWatchlist(const string& title, const int& year);
    void ceva();
    void startWatchlist();
    void nextMovieWatchlist();
    
    void setStorage(const int& s, FileWatchList* f) {this->storage = s; this->filewatchlist = f;}
};
