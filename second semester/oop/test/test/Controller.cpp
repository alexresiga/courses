//
//  Controller.cpp
//  test
//
//  Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Controller.hpp"

void Controller::addOrganism(const std::string &type, const int &pop, const bool &imm)
{
    Organism o = Organism(type, pop, imm);
    this->repo.add(o);
}

vector<Organism> Controller::showOrganisms()
{
    Organism aux = Organism("", 0, false);
    vector<Organism> vector = this->repo.getAll();
    for (int i = 0; i < vector.size()-1; i++)
        for (int j = i;j < vector.size(); ++j)
            if (vector[i].getType() > vector[j].getType())
            {
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
    return vector;
}

void Controller::simulate(const string& env)
{

}
