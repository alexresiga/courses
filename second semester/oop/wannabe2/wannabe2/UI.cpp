//
//  UI.cpp
//  wannabe2
//
//  Created by Alex Resiga on 16/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "UI.hpp"
#include <iostream>
using namespace std;

void UI::run()
{
    while (true)
    {
        cout<<"meniu\n";
        int cmd{0};
        cout<<"ENter command: ";
        cin>> cmd;
        if (!cmd) break;
        else if (cmd == 1)
        {
            cout<<"type of analysis: ";
            cin.ignore();
            string type, date;
            getline(cin, type);
            
            cout<<"Date ";
            getline(cin, date);
            if (type == "BMI")
            {
                cout<<"value ";
                double value;
                cin>>value;
                MedicalAnalysis* m = new BMI{date, value};
                this->person.addAnalysis(m);
            }
            else if (type == "BP")
            {
                int sys, dia;
                cout<<"sys value: ";
                cin>>sys;
                cout<<"dia value: ";
                cin>>dia;
                MedicalAnalysis* m = new BP{date, sys, dia};
                this->person.addAnalysis(m);
            }
        }
        else if (cmd == 2)
        {
            for (auto m: this->person.getAllAnalyses()) cout<<m->toString()<<"\n";
        }
        else if (cmd == 3)
        {
            string month;
            cout<<"month";
            cin.ignore();
            getline(cin, month);
            int m;
            m = stoi(month);
            if (this->person.isIll(m))
                cout<<"ill\n";
            else cout<<"not ill\n";
        }
        else if (cmd == 4)
        {
            string filename, start, end;
            cout<<"filename ";
            cin.ignore();
            getline(cin, filename);
            
            cout<<"start ";
            cin>>start;
            
            cout<<"end ";
            cin.ignore();
            getline(cin, end);
            
            this->person.writeToFile(filename, start, end);
            
        }
    }
}
