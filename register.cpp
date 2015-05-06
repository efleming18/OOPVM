#include "register.hpp"

#include <cassert>

registerIF::registerIF()
    : stackReg(0)
    , pcReg(0)
{
    data.insert(std::pair<int, int>(0, 1));
}

void registerIF::store(int reg, int val)
{
    if (reg <= 0)
    {
        assert(false);
        return;
    }

    if (data.find(reg) == data.end())
    {
        data.insert(std::pair<int, int>(reg, 0));
    }

    data.find(reg)->second = val;
}

int registerIF::value(int reg)
{
    assert(reg >= 0);

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
