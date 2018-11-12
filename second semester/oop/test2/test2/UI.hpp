//
//  UI.hpp
//  test2
//
//  Created by Alex Resiga on 17/05/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Controller.hpp"

class UI
{
protected:
    Controller ctrl;
    
public:
    UI(const Controller& c): ctrl{c}{}
    void run();
};
