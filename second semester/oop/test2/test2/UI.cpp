//
//  UI.cpp
//  test2
//
//  Created by Alex Resiga on 17/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "UI.hpp"
#include <iostream>

void UI::run()
{
    while (true) {
        cout<<"\n\n1.add new car\n2.show all cars\n";
        int cmd{0};
        cout<<"Enter command: ";
        cin>>cmd;
        if (cmd==0) break;
        if (cmd == 1)
        {
            int d, aut=0;
            string f="", e;
            cout<<"enter number of doors ";
            cin>>d;
            cout<<"enter engine type ";
            cin.ignore();
            getline(cin, e);
            if (e == "electric")
            {
                cout<<"enter autonomy: ";
                cin>>aut;
                cin.ignore();
            }else{
            cout<<"enter fuel type: ";
                cin>>f;}
            Car* car = this->ctrl.addCar(d, e, f, aut);
            cout<<car->toString();
        }
        else if (cmd == 2)
        {
            for(auto c: this->ctrl.getAll())
            {
                cout<<c->toString()<<"\n";
            }
        }
        else if (cmd == 3)
        {
            int price;
            cout<<"enter price: ";
            cin>>price;
            cin.ignore();
            string filename;
            getline(cin, filename);
            this->ctrl.writeToFile(filename, this->ctrl.getCars(price));
        }
    }
}
