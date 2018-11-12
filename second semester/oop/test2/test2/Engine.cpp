//
//  Engine.cpp
//  test2
//
//  Created by Alex Resiga on 17/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Engine.hpp"

#include <string>
#include <sstream>

using namespace std;

double ElectricEngine::getPrice() const
{
    return this->basePrice+ this->autonomy*0.01;
}

double TurboEngine::getPrice() const
{
    double p = 0;
    if (this->fuelType == "gasoline") p = 0.01*100;
        else if (this->fuelType == "diesel") p = 0.01*150;
    return this->basePrice + p;
}

string ElectricEngine::toString() const
{
    stringstream buffer;
    buffer << "Electric engine autonomy: " <<this->autonomy<<";price: "<<this->getPrice();
    return buffer.str();
}

string TurboEngine::toString() const
{
    stringstream buffer;
    buffer<< "turbo engine fuel type: "<< this->fuelType<<";price: "<<this->getPrice();
    return buffer.str();
}
