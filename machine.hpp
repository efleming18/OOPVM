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

#ifndef MACHINE_H
#define MACHINE_H

#include "instruction.hpp"
#include "memory.hpp"
#include "register.hpp"


class machine
{
public:
    // Constructor
    machine(const program& p);

    // Get the memory
    memory* mem();

    // Get the register interface
    registerIF* reg();

    // Run the stored program
    void run();

private:
    // Fetch the instruction at the program counter
    const Instruction* fetch();


    memory      data;     // The memory of the machine
    program     prog;     // The program to run
    registerIF  regBank;  // The machine's registers
};

#endif
