//
//  Tests.cpp
//  test
//
//  Created by Alex Resiga on 19/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "Tests.hpp"
#include <assert.h>
#include "Repository.hpp"
#include "Controller.hpp"

void Tests::testRepo()
{
    Organism o = Organism("a", 100, true);
    Repository r{};
    r.add(o);
    assert(r.getAll().size() == 1);
    r.add(o);
    assert(r.getAll()[0].getPop() == 200);
}

void Tests::testController()
{
    Organism o = Organism("a", 100, true);
    Repository r{};
    Controller ctrl{r};
    ctrl.addOrganism("a", 100, true);
    assert(ctrl.getRepo().getAll().size() == 1);
}
