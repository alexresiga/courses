//
//  main.cpp
//  test
//
//  Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include <iostream>
#include "UI.hpp"
#include "Tests.hpp"

int main() {
    
    Tests::testRepo();
    Tests::testController();
    
    Repository repo{};
    
    Controller ctrl{repo};
    ctrl.addOrganism("da", 120, true);
    ctrl.addOrganism("a", 100, false);
    ctrl.addOrganism("a", 40, true);
    UI ui{ctrl};
    
    ui.run();
    return 0;
}
