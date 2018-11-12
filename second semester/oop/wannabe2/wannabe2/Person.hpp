//
//  Person.hpp
//  wannabe2
//
//  Created by Alex Resiga on 16/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include "MedicalAnalysis.hpp"
#include <vector>

using namespace std;

class Person
{
private:
    string name;
    
protected:
    vector<MedicalAnalysis*> analysis;
    
public:
    Person(const string& _name): name{_name} {}
    virtual ~Person() {}
    bool addAnalysis(MedicalAnalysis* m);
    vector<MedicalAnalysis*> getAllAnalyses() const {return this->analysis;}
    vector<MedicalAnalysis*> getAnalysesByMonth(int month) ;
    bool isIll(int month) const;
    vector<MedicalAnalysis*> getAnalysesBetweenTwoDates(const string& start, const string& end) ;
    void writeToFile(const string& filename, const string& start, const string& end);
};
