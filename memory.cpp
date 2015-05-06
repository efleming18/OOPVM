#include "memory.hpp"

#include <cassert>

memory::memory()
	: data(1 << 10)
{

}

memory::memory(int size)
	: data(size)
{

}

int memory::readByte(int index)
{
    assert(index >= 0);
	resize(index);
	return data.at(index);
}

int memory::readWord(int index)
{
    assert(index >= 0);
	resize(index+3);

	int retval = 0;
	for (int i = 0; i < 4; ++i)
	{
        int temp = data.at(index+i);
        temp = temp << (24 - 8*i);
		retval += data.at(index+i) << (24 - 8*i);
	}

	return retval;
}

void memory::writeByte(int index, unsigned char d)
{
    assert(index >= 0);
	resize(index);
	data.at(index) = d;
}

void memory::writeWord(int index, int d)
{
    assert(index >= 0);
	resize(index+3);

	for (int i = 0; i < 4; ++i)
	{
		data.at(index+i) = d >> (24 - 8*i);
	}
}

void memory::resize(unsigned int index)
{
	if (index >= data.size())
	{
        data.resize(index+1);
	}
}
