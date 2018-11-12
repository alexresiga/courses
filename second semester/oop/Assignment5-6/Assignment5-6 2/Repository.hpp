//
//  Repository.hpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include <iostream>
#include "DynamicVector.hpp"
#include "Movie.h"
#include <vector>
using namespace std;

class Repository
{
private:
    vector<Movie> movies;
    string filename;
    
public:
    Repository() {}
    
    /*
     Constructor with parameters.
     Initializes an object of type repository, by reading data from the given file.
     Throws: FileException - if the file cannot be opened.
     */
    Repository(const string& filename);
    
    vector<Movie>::iterator findMovie(const Movie& m);
    
    void addMovie(const Movie& m);
    
    void removeMovie(const Movie& m);
    
    void updateMovie(const Movie& m);
    
    vector<Movie>& getMovies() {return movies;}
    
private:
    void readFromFile();
    void writeToFile();
};
