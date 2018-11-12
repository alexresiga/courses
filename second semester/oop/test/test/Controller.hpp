//
//  Controller.hpp
//  test
//
//  Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once

#include "Repository.hpp"
#include <string>

using namespace std;

class Controller
{
private:
    Repository repo;
    
public:
    Controller(const Repository& r): repo{r} {}
    //method for adding organism
    void addOrganism(const string& type, const int& pop, const bool& imm);
    //method for showing organism
    vector<Organism> showOrganisms();
    //method for getting repo
    Repository getRepo() {return this->repo;}
    //simulate day
    void simulate(const string& env);
};
