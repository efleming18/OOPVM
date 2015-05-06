#include "machine.hpp"

#include <cassert>

machine::machine(const program& p)
    : prog(p)
{

}

memory* machine::mem()
{
    return &data;
}

registerIF* machine::reg()
{
    return &regBank;
}

void machine::run()
{
    machine start = *this;

    while (const Instruction* i = fetch())
    {
        machine temp = *this;
        execute(*i, this);
    }

    machine final = *this;
    int two = 2;
}

const Instruction* machine::fetch()
{
    unsigned int pc = *(reg()->pc());
    if (pc >= prog.size())
    {
        return NULL;
    }

    const Instruction* i = &prog.at(pc);
    (*(reg()->pc()))++;
    return i;
}