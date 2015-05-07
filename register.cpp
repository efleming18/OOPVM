//
// Benjamin Riggs
//
// University of Akron
// Object Oriented Programming
// Dr. Andrew Sutton
// 5/7/2015
//
// Virtual Machine Project
// Register Interface
//

#include "register.hpp"

#include <cassert>

registerIF::registerIF()
    : stackReg(0)
    , pcReg(0)
{
    // R0 always stores the value 0
    data.insert(std::pair<int, int>(0, 0));
}

void registerIF::store(int reg, int val)
{
    if (reg <= 0)
    {
        assert(false);
        return;
    }

    // Add the reg if it doesn't exist
    if (data.find(reg) == data.end())
    {
        data.insert(std::pair<int, int>(reg, 0));
    }

    data.find(reg)->second = val;
}

int registerIF::value(int reg)
{
    assert(reg >= 0);

    // Add the reg if it doesn't exist
    if (data.find(reg) == data.end())
    {
        data.insert(std::pair<int, int>(reg, 0));
    }

    return data.at(reg);
}

int* registerIF::stack()
{
    return &stackReg;
}

int* registerIF::pc()
{
    return &pcReg;
}
