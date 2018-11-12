//
//  Validator.cpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Validator.hpp"
#include "ValidatorException.hpp"
#include <string>
using namespace std;

void Validator::validateMovie(const Movie &m)
{
    string errorMsg="";
    if (m.getTitle() == "")
        errorMsg += "\nTitle cannot be empty\n";
    if (m.getGenre() == "")
        errorMsg += "Genre cannot be empty\n";
    if (m.getYear() < 1878)
        errorMsg += "Invalid year\n";
    if (m.getTrailer() == "")
        errorMsg += "Trailer cannot be empty\n";
    
    if (errorMsg.size() > 0)
        throw ValidatorException(errorMsg);
}
