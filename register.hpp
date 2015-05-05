#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <map>

class registerIF
{
public:
    registerIF();

    void store(int reg, int val);

    int value(int reg);

    int* stack();

    int* pc();

private:
    std::map<int, int> data;
    int stackReg;
    int pcReg;
};

#endif
