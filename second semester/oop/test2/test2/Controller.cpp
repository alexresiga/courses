//
//  Controller.cpp
//  test2
//
//  Created by Alex Resiga on 17/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Controller.hpp"

Engine* Controller::createEngine(const std::string & et, const std::string & ft, const int & aut)
{
    Engine* eng{};
    if (et == "electric")
        eng = new ElectricEngine{ft, aut};
    else if (et == "turbo")
        eng = new TurboEngine{ft};
    
    return eng;
}

Car* Controller::addCar(int d, const std::string & et, const std::string &ft, const int & aut)
{
    Engine* engine = createEngine(et, ft, aut);
    Car* car  = new Car{d, engine, et};
    this->cars.push_back(car);
    return car;
}

vector<Car*> Controller::getCars(int price)
{
    vector<Car*> result;
    for (auto c: this->getAll())
    {
        if (c->computePrice() < price)
            result.push_back(c);
    }
    return result;
}

void Controller::writeToFile(std::string filename, vector<Car *> result)
{
    ofstream g(filename);
    for (auto c: result)
    {g<<c->toString();g<<"\n";}
}
