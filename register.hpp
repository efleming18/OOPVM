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

#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <map>

class registerIF
{
public:
    // Constructor
    registerIF();

    // store
    //
    //   Store the given value into the given register
    //   If the register doesn't exist, it will be created
    void store(int reg, int val);

    // value
    //
    //   Obtain the value stored int he given register
    //   If the register doesn't exist, it will be created
    int value(int reg);

    // stack
    //
    //   Return a pointer to the stack pointer register
    int* stack();

    // pc
    //
    //   Return a pointer to the program counter register
    int* pc();

private:
    std::map<int, int> data;  // The register representation
    int stackReg;  // The value of the stack pointer register
    int pcReg;     // The value of the program counter register
};

#endif
