//
//  Organism.cpp
//  test
//
//  Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Organism.hpp"

Organism::Organism(const string& type, const int& pop, const bool& imm)
{
    this->type = type;
    this->population = pop;
    this->immunity = imm;
}
