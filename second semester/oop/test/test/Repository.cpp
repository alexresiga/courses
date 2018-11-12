//
//  Repository.cpp
//  test
//
//  Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Repository.hpp"
#include <iostream>

using namespace std;
void Repository::add(Organism o)
{
    bool ok =false;
    for (int i = 0; i < this->organisms.size(); ++i)
        if (this->organisms[i] == o)
        {
            this->organisms[i].setPop(o.getPop());
            ok = true;
        }
    if (!ok) {this->organisms.push_back(o);cout<<"New organism added\n";}
}

vector<Organism> Repository::getAll()
{
    return this->organisms;
}
