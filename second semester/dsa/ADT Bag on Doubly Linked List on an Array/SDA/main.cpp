//
//  main.cpp
//  SDA
//
//  Created by Alex Resiga on 31/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include <iostream>
#include "DLLA.hpp"
#include <string>
#include <iostream>

using namespace std;
void printMenu()
{
    string res = "\n";
    res += "Manage current shopping cart:\n";
    res += "\t1. Add new product to the cart\n";
    res += "\t2. Remove product from cart\n";
    res += "\t3. Search for item in shopping cart\n";
    res += "\t4. List all items in cart.\n";
    res += "\t0. Exit.\n";
    cout << res;
}
int main()
{
    //Tests t{};
    //t.all();
    Product p1{ 1, "car", "nice description" };
    Product p2{ 2, "house", "another description" };
    Product p3{ 3, "lorem", "ipsum" };
    Bag bag{};
    bag.add(p1);bag.add(p2);bag.add(p3);
    while (true)
    {
        int command{ 0 };
        printMenu();
        cout << "Enter command: ";
        cin >> command;
        if (!command)
            break;
        else if (command == 1)
        {
            int id;
            string name, description;
            cout << "Enter product id: ";
            cin >> id;
            cin.ignore();
            cout << "Enter product name: ";
            getline(cin, name);
            cout << "Enter product description: ";
            getline(cin, description);
            Product p{ id, name, description };
            bag.add(p);
        }
        else if (command == 2)
        {
            int id;
            string name, description;
            cout << "Enter product id: ";
            cin >> id;
            cin.ignore();
            cout << "Enter product name: ";
            getline(cin, name);
            cout << "Enter product description: ";
            getline(cin, description);
            Product p{ id, name, description };
            bag.remove(p);
        }
        else if (command == 3)
        {
            int id;
            string name, description;
            cout << "Enter product id: ";
            cin >> id;
            cin.ignore();
            cout << "Enter product name: ";
            getline(cin, name);
            cout << "Enter product description: ";
            getline(cin, description);
            Product p{ id, name, description };
            bool answer = bag.search(p);
            if (answer) cout << "Existing product in cart.\n";
            else cout << "\nNon existing product in cart.\n";
        }
        else if (command == 4)
        {
            DLLAIterator it{ bag };
            if (it.isEmpty())
                cout << "\nEmpty cart currently.\n\n";
            
            else
                while (it.valid())
                {
                    cout <<  it.getCurrent().toString();
                    it.next();
                }
        }
        else if (command == 5)
        {
            int id;
            int freq[100] = {0};
            cout<<"enter id: ";
            cin>>id;
            cin.ignore();
            DLLAIterator it {bag};
            while (it.valid())
            {
                freq[it.getCurrent().getID()]++;
                it.next();
            }
            cout<<"product with id "<<id<<" appears "<<freq[id]<<" times";
        }
    }
    
    return 0;
}
