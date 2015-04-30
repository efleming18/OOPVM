//Zachary Puster
//instruction.hpp

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>

class add
{
public:
	 add(int, int, int);
	 addi(int, int, int);
	
};

class sub
{
public:
	 sub(int, int, int);
	 subi(int, int, int);
	
};


class mult
{
public:
	 mult(int, int, int);
	 multi(int, int, int);
	
};

class div
{
public:
	 div(int, int, int);
	 divi(int, int, int);
	
};

class mem_access
{
public:
	load(int, int);
	store(int, int);
};

class branch
{
public:
	bnez(std::vector, int, int);
	beqz(std::vector, int, int);
}

class jump
{
public:
	jump(std::vector, int);
}

#endif

int number_switch(int);