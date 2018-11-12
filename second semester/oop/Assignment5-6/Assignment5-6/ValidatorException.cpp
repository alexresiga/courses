//
//  ValidatorException.cpp
//  Assignment5-6
//
//  Created by Alex Resiga on 26/04/2018.
//  Copyright © 2018 Alex Resiga. All rights reserved.
//

#include "ValidatorException.hpp"

const string& ValidatorException::getMessage() const
{
    return this->message;
}

const string& RepoException::getMessage() const
{
    return this->message;
}
