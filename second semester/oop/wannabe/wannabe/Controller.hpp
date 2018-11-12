//
//  Controller.hpp
//  wannabe
//
//  Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//
#pragma once
#include <string>
#include "Repository.hpp"

using namespace std;

class Controller
{
private:
    Repository repo;
public:
    Controller(const Repository& r): repo{r} {}
};
