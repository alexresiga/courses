//
//  UI.cpp
//  test
//
//  Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "UI.hpp"
#include <iostream>

using namespace std;

void UI::printMenu()
{
    cout<<endl;
    cout<<"1. Add new population.\n";
    cout<<"2. Show the list of all populations.\n";
    cout<<"3. Simulate a day.\n";
}

void UI::addUI()
{
    string type;
    int pop;
    bool imm;
    
    cout<<"Enter type: ";
    getline(cin, type);
    cout<<"Enter population: ";
    cin>>pop;
    cin.ignore();
    cout<<"Enter immunity: ";
    cin>>imm;
    cin.ignore();
    this->ctrl.addOrganism(type, pop, imm);
}

void UI::showUI()
{
    vector<Organism> vector = this->ctrl.showOrganisms();
    for (int i = 0; i < vector.size(); ++i)
    {
        cout<<vector[i].getType()<<", "<<vector[i].getPop()<<", "<<vector[i].getImm()<<"\n";
    }
}

void UI::simulateDay()
{
    string user;
    cout<<"Enter env: ";
    getline(cin, user);
    this->ctrl.simulate(user);
    
}
void UI::run()
{
    while (true)
    {
    UI::printMenu();
    int command{0};//command = 0
    cout<<"Enter command: ";
    cin>>command;
        switch (command) {
            case 1:
                this->addUI();
                break;
            case 2:
                this->showUI();
                break;
            case 3:
                this->simulateDay();
        }
    }
}

