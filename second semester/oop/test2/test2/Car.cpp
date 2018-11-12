//
//  Car.cpp
//  test2
//
//  Created by Alex Resiga on 17/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Car.hpp"
#include <sstream>

double Car::computePrice() const
{
    double base = 7000;
    if (this->numberOfDoors == 4) base += 1500;
    return base + this->engine->getPrice();
}

string Car::toString() const
{
    stringstream buffer;
    buffer<<"no of doors: "<<this->numberOfDoors<<"; engine type: "<<this->type<< " ->> engine: "<<this->engine->toString()<<";; "<<this->computePrice();
    return buffer.str();
}

ostream& operator<<(ostream& out, Car* car)
{
    out<< car->toString();
    return out;
}
