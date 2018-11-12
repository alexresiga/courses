//
//  Repository.cpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/03/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Repository.hpp"
#include <string>
#include <fstream>
#include "ValidatorException.hpp"
#include "Validator.hpp"

using namespace std;

Repository::Repository(const string& filename)
{
    this->filename = filename;
    this->readFromFile();
}

vector<Movie>::iterator Repository::findMovie(const Movie &m)
{
    /*
    Movie* moviesInDV = this->movies.getAllElems();
    
    if (moviesInDV == NULL)
        return -1;
    
    for (int i = 0; i< this->movies.getSize(); ++i)
    {
        Movie n = moviesInDV[i];
        if (n == m)
            return i;
    }
    */
    vector<Movie>::iterator it;
    it = find(this->movies.begin(), this->movies.end(), m);
    return it;
}

void Repository::addMovie(const Movie &m)
{
    try {
    Validator::validateMovie(m);
    } catch (ValidatorException e ) {
        cout<<e.getMessage();
        return;
    }
    
    if (findMovie(m) == this->movies.end())
    {
        this->movies.push_back(m);
        this->writeToFile();
    }
    else throw RepoException("\nalready existing movie\n");
}

void Repository::removeMovie(const Movie &m)
{
    if (findMovie(m) != this->movies.end())
    {
        this->movies.erase(findMovie(m));
        this->writeToFile();
    }
    else
         throw RepoException("\nnon existing movie\n");
}

void Repository::updateMovie(const Movie &m)
{
    if (findMovie(m) == this->movies.end())
        throw RepoException("\n non existing movie\n");
    
    else
    {
        this->movies.erase(findMovie(m));
        this->movies.insert(findMovie(m), m);
        this->writeToFile();
    }
}

void Repository::readFromFile()
{
    ifstream file(this->filename);
    
    
    Movie m;
    while(file>>m)
    this->movies.push_back(m);
    file.close();
}

void Repository::writeToFile()
{
    ofstream file(this->filename);
    
    for (auto m: this->movies)
    {
        file << m;
    }
    
    file.close();
}
