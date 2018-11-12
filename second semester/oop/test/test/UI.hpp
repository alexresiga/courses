//
//  UI.hpp
//  test
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
    static void printMenu();
    void addUI();
    void showUI();
    void simulateDay();
    void run();
};
