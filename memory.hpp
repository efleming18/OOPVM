//
// Benjamin Riggs
//
// University of Akron
// Object Oriented Programming
// Dr. Andrew Sutton
// 5/7/2015
//
// Virtual Machine Project
// Memory Interface
//

#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

class memory
{
public:
    // Constructor
    //   Defaults the size to 1000 bytes
	memory();

    // Constructor
    //   size - The default memory size
	memory(int size);

    // readByte
    //
    //   Read in a single byte from the memory, starting
    //   at the given byte index
	int readByte(int index);

    // readWord
    //
    //   Read in a single word from the memory, starting
    //   at the given byte index
	int readWord(int index);

    // writeByte
    //
    //   Write a single byte of data to the given byte
    //   index in memory
    void writeByte(int index, unsigned char d);

    // writeWord
    //
    //   Write a single word of data to the given byte
    //   index in memory
	void writeWord(int index, int d);

private:
    // resize
    //
    //   Check the memory vector against the given index
    //   to see if it needs resized, and act accordingly
    void resize(unsigned int index);


    std::vector<unsigned char> data;  // The memory representation
};

#endif
