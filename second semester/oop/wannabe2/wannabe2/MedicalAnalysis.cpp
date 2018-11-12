//
//  MedicalAnalysis.cpp
//  wannabe2
//
//  Created by Alex Resiga on 16/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "MedicalAnalysis.hpp"
#include <sstream>
#include <string>
using namespace std;

string MedicalAnalysis::toString() const
{
    stringstream buffer;
    buffer << "date: " << this->date;
    return buffer.str();
}

string BMI::toString() const
{
    stringstream buffer;
    buffer<< "BMI: " <<this->date<<" " << this->value << " --> "<<this->isResultOK();
    return buffer.str();
}

string BP::toString() const
{
    stringstream buffer;
    buffer<< "BP: " <<this->date<<" " << this->systolicValue<<", "<< this->diastolicValue << " --> "<<this->isResultOK();
    return buffer.str();
}

bool BMI::isResultOK() const
{
    return this->value >= 18.5 and this->value <= 25;
}

bool BP::isResultOK() const
{
    return this->systolicValue >= 90 and this->systolicValue <= 119 and this->diastolicValue >= 60 and this->diastolicValue <= 79;
}

ostream& operator<<(ostream& out, MedicalAnalysis* m)
{
    out<< m->toString();
    return out;
}
