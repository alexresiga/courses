//
//  Controller.hpp
//  test2
//
//  Created by Alex Resiga on 17/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include "Car.hpp"
#include <vector>

class Controller
{
protected:
    vector<Car*> cars;
    
private:
    Engine* createEngine(const string&, const string&, const int&);

public:
    Car* addCar(int, const string&,const string&, const int&);
    vector<Car*> getAll() {return this->cars;}
    vector<Car*> getCars(int price);
    void writeToFile(string, vector<Car*>);
    
};
