#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

class memory
{
public:
	memory();

	memory(int size);

	int readByte(int index);

	int readWord(int index);

    void writeByte(int index, unsigned char d);

	void writeWord(int index, int d);

private:
	void resize(int index);

	std::vector<unsigned char> data;
};

#endif MEMORY_H
