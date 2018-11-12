//
//  Movie.h
//  Assignment5-6
//
//  Created by Alex Resiga on 26/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Movie
{
private:
    string title;
    string genre;
    unsigned int year;
    unsigned int likes;
    string trailer;
    
public:
    //default constructor
    Movie();
    //constructor with parameters
    Movie(const string& title, const string& genre, const unsigned int& year, const unsigned int& likes, const string& trailer);
    
    //copy constructor
    //Movie(const Movie* m);
    
    //overloading for eq operator
    inline bool operator==(const Movie&b) {return this->getTitle() == b.getTitle() and this->getYear() == b.getYear();}
    
    //title getter
    string getTitle() const {return this->title;}
    //genre getter
    string getGenre() const {return genre;}
    
    //year getter
    unsigned int getYear() const {return year;}
    //likes getter
    unsigned int getLikes() const {return likes;}
    
    //trailer getter
    string getTrailer() const {return trailer;}
    
    void increaseLikes() { this->likes++;}
    
    //open trailer in browser
    void play();
    
    friend ifstream& operator>>(ifstream& is, Movie& m);
    friend ofstream& operator<<(ofstream& os, const Movie& m);
        
};
