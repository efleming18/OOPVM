//Zachary Puster
//Instruction.cpp

#include "instruction.hpp"


add::add(int write_reg, int reg_a, int reg_b)
{
	int result;
	result = value(reg_a) + value(reg_b);
	store(write_reg, result);
}

add::addi (int write_reg, int reg_a, int immd)
{
	int result;
	result = value(reg_a) + immd;
	store(write_reg, result);
}

sub::sub(int write_reg, int reg_a, int reg_b)
{
	int result;
	result = value(reg_a) - value(reg_b);
	store(write_reg, result);
}

sub::subi (int write_reg, int reg_a, int immd)
{
	int result;
	result = value(reg_a) - immd;
	store(write_reg, result);
}

mult::mult(int write_reg, int reg_a, int reg_b)
{
	int result;
	result = value(reg_a) * value(reg_b);
	store(write_reg, result);
}

mult::milti (int write_reg, int reg_a, int immd)
{
	int result;
	result = value(reg_a) * immd;
	store(write_reg, result);
}

div::div(int write_reg, int reg_a, int reg_b)
{
	int result;
	result = value(reg_a) / value(reg_b);
	store(write_reg, result);
}

div::divi (int write_reg, int reg_a, int immd)
{
	int result;
	result = value(reg_a) / immd;
	store(write_reg, result);
}

mem_access::read (int reg, int memory)
{
	reg = readWord(memory);
	return reg;
}

mem_access::write_reg (int reg, int memory)
{
	writeWord(memory, reg);
}

branch::bnez(vector &myvector, int target, int reg)
{
	if (value(reg) == 0)
		jump.jump(myvector, target);
}

branch::beqz(vector &myvector, int target, int reg)
{
	if (value(reg) != 0)
		jump.jump(myvector, target);
}

jump::jump(vector &myvector, int target)
{
	myvector.at(target);
}