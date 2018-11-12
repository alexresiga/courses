//
//  Repository.hpp
//  test
//
//  Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include <vector>
#include "Organism.hpp"

class Repository
{
private:
    vector<Organism> organisms;
    
public:
    Repository() {}
    
    //method for adding organism to repo
    void add(Organism o);
    //method for getting all organisms
    vector<Organism> getAll();
};
