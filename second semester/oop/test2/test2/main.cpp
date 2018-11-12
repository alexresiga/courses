//
//  main.cpp
//  test2
//
//  Created by Alex Resiga on 17/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "UI.hpp"

int main()
{
    Controller ctrl{};
    ctrl.addCar(4, "electric", "diesel", 123);
    ctrl.addCar(2, "turbo", "gasoline", 0);
    UI ui{ctrl};
    
    ui.run();
}
