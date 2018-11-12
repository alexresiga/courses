//
//  Car.hpp
//  test2
//
//  Created by Alex Resiga on 17/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include "Engine.hpp"
#include <fstream>

class Car
{
private:
    int numberOfDoors;
public:
    Engine* engine;
    string type;
    

public:
    Car(int d, Engine* eng, string type): numberOfDoors{d}, engine{eng}, type{type} {}
    double computePrice() const;
    string toString() const;
    friend ostream& operator<<(ostream& out, Car* car);
};
