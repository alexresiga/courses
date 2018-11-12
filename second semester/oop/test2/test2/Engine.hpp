//
//  Engine.hpp
//  test2
//
//  Created by Alex Resiga on 17/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include <string>

using namespace std;

class Engine
{
protected:
    string fuelType;
    double basePrice = 3000;
    
public:
    Engine(const string& f): fuelType{f}{}
    virtual double getPrice() const {return this->basePrice;}
    virtual string toString() const = 0;
    
};


class ElectricEngine: public Engine
{
private:
    int autonomy;
    
public:
    ElectricEngine(const string& f, const int& a): Engine{f}, autonomy{a}{}
    double getPrice() const override;
    string toString() const override;
};

class TurboEngine: public Engine
{
public:
    TurboEngine(const string& f): Engine{f}{}
    double getPrice() const override;
    string toString() const override;
    
};
