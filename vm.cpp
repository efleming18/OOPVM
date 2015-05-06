#include "machine.hpp"

#include <cassert>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Requires a .o file to run";
        return 0;
    }

    program p = build(argv[1]);
    machine m(p);
    m.run();

    return 0;
}
