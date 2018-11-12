//
//  UI.hpp
//  wannabe2
//
//  Created by Alex Resiga on 16/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#pragma once
#include "Person.hpp"

class UI
{
protected:
    Person person;
public:
    UI(const Person& p): person{p} {}
    void run();
};
