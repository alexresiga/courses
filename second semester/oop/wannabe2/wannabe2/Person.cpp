//
//  Person.cpp
//  wannabe2
//
//  Created by Alex Resiga on 16/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Person.hpp"
#include <fstream>
#include <iostream>

using namespace std;

bool Person::addAnalysis(MedicalAnalysis *m)
{
    this->analysis.push_back(m);
    return true;
}

vector<MedicalAnalysis*> Person::getAnalysesByMonth(int month)
{
    vector<MedicalAnalysis*> result;
    /*
    for (auto m: this->getAllAnalyses())
    {
        string date = m->getDate();
        if (stoi(date.substr(5,2)) == month) result.push_back(m);
    }*/
    copy_if(this->getAllAnalyses().begin(), this->getAllAnalyses().end(), back_inserter(result), [month](MedicalAnalysis* m){return stoi(m->getDate().substr(5,2)) == month;});
    return result;
}

vector<MedicalAnalysis*> Person::getAnalysesBetweenTwoDates(const std::string &start, const std::string &end) 
{
    vector<MedicalAnalysis*> result;
    cout<<start <<" "<<end;
    for (auto m: this->getAllAnalyses())
    {
        string date = m->getDate();
        cout<<date<<"\n";
        if (date >= start and date <= end)
        result.push_back(m);
    }
    //copy_if(this->getAllAnalyses().begin(), this->getAllAnalyses().end(), back_inserter(result), [start, end](MedicalAnalysis* m) {return m->getDate() >= start and m->getDate() <= end;});

    return result;
}

bool Person::isIll(int month) const
{
    for (auto m: this->getAllAnalyses())
        if (!m->isResultOK())
            return false;
    return true;
}

void Person::writeToFile(const std::string &filename, const std::string &start, const std::string &end)
{
    ofstream g(filename);
    
    vector<MedicalAnalysis*> result = this->getAnalysesBetweenTwoDates(start, end);
    for(auto m: result) g<<m<<"\n";
}
