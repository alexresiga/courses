//
//  Movie.cpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//
#include <fstream>
#include "Movie.h"
#include <stdlib.h>
#include "Utils.hpp"
#include <vector>

using namespace std;

Movie::Movie(): title(""), genre(""), year(0), likes(), trailer("") {}

Movie::Movie(const string& title, const string& genre, const unsigned int& year, const unsigned int& likes, const string& trailer)
{
    this->title = title;
    this->genre = genre;
    this->year = year;
    this->likes = likes;
    this->trailer = trailer;
}

void Movie::play()
{
    string url = "open ";
    url += this->getTrailer();
    system(url.c_str());
}

ifstream& operator>>(ifstream& is, Movie& m)
{
    is >> m.title >> m.genre >> m.year >> m.likes >> m.trailer;
    
    return is;
}


ofstream & operator<<(ofstream & os, const Movie & m)
{
    os << m.getTitle() << " " << m.getGenre() << " " << m.getYear() << " " << m.getLikes() << " " << m.getTrailer() << "\n";
    return os;
}
