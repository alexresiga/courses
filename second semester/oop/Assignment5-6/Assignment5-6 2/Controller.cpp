//
//  Controller.cpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Controller.hpp"
#include <string>
#include <vector>

using namespace std;

void Controller::addMovieToRepo(const string &title, const string &genre, const unsigned int &year, const unsigned int &likes, const string &trailer)
{
    Movie m{title, genre, year, likes, trailer};
    this->repo.addMovie(m);
}

void Controller::removeMovieFromRepo(const string &title, const unsigned int &year)
{
    Movie m{title, "", year, 0, ""};
    this->repo.removeMovie(m);
}

void Controller::updateMovieRepo(const string &title, const string &genre, const unsigned int &year, const unsigned int &likes, const string &trailer)
{
    Movie m{title, genre, year, likes, trailer};
    this->repo.updateMovie(m);
}

void Controller::addMovieToWatchList(const Movie &movie)
{
    this->watchlist.addToWatchlist(movie);
}

void Controller::addMovieByGenre(const string &genre)
{
    vector<Movie> movies(this->repo.getMovies());
    int i=0;
    while (i< movies.size())
    {
        Movie m = movies[i];
        if (m.getGenre() != genre)
            movies.erase(movies.begin()+i);
        else i++;
    }
    
    int j=0, c=1;
    while (j < movies.size())
    {
        
        Movie m = movies[j];
        cout<<m.getTitle() << " - " << m.getGenre() << ", " << m.getYear() << ": " << m.getLikes() <<" likes.\n";
        m.play();
        string answer;
        cout<<"Do you want to add this movie to your watchlist?\n";
        getline(cin, answer);
        if (answer == "yes")
            this->watchlist.addToWatchlist(m);
        (j == movies.size()-1) ? j=0 : j++;
        c++;
        if (c%movies.size() == 1)
        {
            string ceva;
            cout<<"\nExit?\n";
            getline(cin, ceva);
            if (ceva == "yes") break;
        }
    }
}

void Controller::deleteMovieWatchlist(const std::string &title, const int &year)
{
    Movie m = this->watchlist.deleteFromWatchlist(title, year);
    this->repo.updateMovie(m);
    
}

void Controller::startWatchlist()
{
    this->filewatchlist->displayWatchList(this->watchlist.getMovies());
    this->watchlist.play(this->storage);
}
void Controller::ceva()
{
    WatchList w = this->getWatchList();
    for (int i = 0; i< w.getMovies().size(); i++)
        cout<<w.getMovies()[i].getTitle()<<endl;
}
void Controller::nextMovieWatchlist()
{
    this->watchlist.next();
}
