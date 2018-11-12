//
//  Product.hpp
//  SDA
//
//  Created by Alex Resiga on 06/06/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//
#pragma once

#include <string>
#include <sstream>

using namespace std;

class Product
{
private:
    int id;
    string name;
    string description;
    
public:
    Product() : id{ 0 }, name{ "" }, description{ "" } {}
    Product(int id, string n, string d) : id{ id }, name{ n }, description{ d } {}
    string toString() { ostringstream res; res << this->id << ": " << this->name << " ->" << this->description << "\n"; return res.str(); }
    int getID() { return this->id; }
};

