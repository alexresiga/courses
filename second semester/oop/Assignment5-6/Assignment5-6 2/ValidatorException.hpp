//
//  ValidatorException.hpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include <string>
using namespace std;

class ValidatorException
{
private:
    string message;
public:
    ValidatorException(const string& msg): message{msg}{};
    const string& getMessage() const;
};

class RepoException
{
private:
    string message;
public:
    RepoException(const string& msg): message{msg}{};
    const string& getMessage() const;
};
