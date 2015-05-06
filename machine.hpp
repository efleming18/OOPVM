#ifndef MACHINE_H
#define MACHINE_H

#include "instruction.hpp"
#include "memory.hpp"
#include "register.hpp"

typedef std::vector<Instruction> program;


class machine
{
public:
    machine(const program& p);

    memory* mem();

    registerIF* reg();

    void run();

private:
    const Instruction* fetch();


    memory data;
    program prog;
    registerIF regBank;
};

#endif
