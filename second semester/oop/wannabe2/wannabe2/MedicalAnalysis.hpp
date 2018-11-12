//
//  MedicalAnalysis.hpp
//  wannabe2
//
//  Created by Alex Resiga on 16/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include <string>
#include <fstream>

using namespace std;

class MedicalAnalysis
{
protected:
    string date;
public:
    MedicalAnalysis(string _date): date{_date} {}
    virtual ~MedicalAnalysis() {};
    virtual bool isResultOK() const = 0;
    virtual string toString() const;
    string getDate() {return this->date;}
    friend ostream& operator<<(ostream& out, MedicalAnalysis* m);
};

class BMI: public MedicalAnalysis
{
protected:
    double value;
public:
    virtual ~BMI() {}
    BMI(const string& _date, const double& _value): MedicalAnalysis{ _date}, value{ _value} {}
    bool isResultOK() const override;
    string toString() const override;
    friend ostream& operator<<(ostream& out, MedicalAnalysis* m);
};

class BP: public MedicalAnalysis
{
protected:
    int systolicValue;
    int diastolicValue;
public:
    virtual ~BP() {}
    BP(const string& _date, const int& s, const int& v): MedicalAnalysis{_date}, systolicValue{s}, diastolicValue{v} {}
    bool isResultOK() const override;
    string toString() const override;
    friend ostream& operator<<(ostream& out, MedicalAnalysis* m);

};
