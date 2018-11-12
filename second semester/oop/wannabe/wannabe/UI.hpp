//
//  UI.hpp
//  wannabe
//
//  Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//
#pragma once
#include <string>
#include "Controller.hpp"
using namespace std;

class UI
{
private:
    Controller ctrl;
    
public:
    UI(const Controller& c): ctrl(c) {}
    
    void run();
private:
    static void printMenu();
    void addUI();
};
