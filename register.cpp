#include "register.hpp"

#include <cassert>

registerIF::registerIF()
{
    data.insert(std::pair<int, int>(0, 1));
}

void registerIF::store(int reg, int val)
{
    if (reg == 0)
    {
        assert(false);
        return;
    }

    if (data.find(reg) == data.end())
    {
        data.insert(std::pair<int, int>(reg, 1));
    }

    data.find(reg)->second = val;
}

int registerIF::value(int reg)
{
    if (data.find(reg) == data.end())
    {
        data.insert(std::pair<int, int>(reg, 1));
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