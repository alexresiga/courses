//
//  Organism.hpp
//  test
//
//  Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include <string>

using namespace std;

class Organism
{
private:
    string type;
    int population;
    bool immunity;
    
public:
    Organism();
    
    Organism(const string& type, const int& population, const bool& immunity);
    inline bool operator==(const Organism&b) {return this->getType() == b.getType();}

    string getType() const {return type;}
    int getPop() const {return population;}
    bool getImm() const {return immunity;}
    void setPop(int nr) {this->population+=nr;}
};
