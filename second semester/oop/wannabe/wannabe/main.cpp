//
//  main.cpp
//  wannabe
//
//  Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include <iostream>
#include "UI.hpp"
#include <vector>
using namespace std;

int main() {
    
    Repository repo{};
    
    Controller ctrl{repo};
    
    UI ui{ctrl};
    
    ui.run();
    
    vector<int> a;
    a.push_back(5);
    a.push_back(23);
    for (vector<int>::iterator it=a.begin(); it != a.end(); ++it)
    {
        cout<< *it<<" ";
    }
    cout<<endl;
    for (int i =0; i < a.size() ;++i)
    {
        cout<< a[i]<<" ";
    }
    
    
    return 0;
}
