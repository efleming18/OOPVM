//
// Benjamin Riggs
//
// University of Akron
// Object Oriented Programming
// Dr. Andrew Sutton
// 5/7/2015
//
// Virtual Machine Project
// Machine Object
//

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
    // Execute instructions until one can't be obtained
    while (const Instruction* i = fetch())
    {
        execute(*i, this);
    }
}

const Instruction* machine::fetch()
{
    // If there is no instruction at the current pc, return NULL
    unsigned int pc = *(reg()->pc());
    if (pc >= prog.size())
    {
        return NULL;
    }

    // Otherwise, return the instruction and increment the pc
    const Instruction* i = &prog.at(pc);
    (*(reg()->pc()))++;
    return i;
}
