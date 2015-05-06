//Zachary Puster
//instruction.hpp

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>


struct Arithmetic_inst 
{
	int write_reg;
	int reg_a;
	int reg_b;
};

struct Immd_arithmetic_inst 
{
	int write_reg;
	int reg_a;
	int immd;
};

struct Jump
{
	int target;
};

struct Branch
{
	int condition_reg;
	int target;
};

struct Access
{
	int reg;
	int memory;
};

struct Instruction
{
 enum { add, addi, sub, subi, mult, multi, div, divi, load, store, bnez, beqz, jump } type;
 union 
 	{
	 	Immd_arithmetic_inst iai;
	 	Branch br;
	 	Jump j;
	 	Arithmetic_inst ai;
	 	Access ac;
	 } op;
};


/*
struct instruction
{
	void Add(int write_reg, int reg_a, int reg_b)
	{
		int result;
		result = value(reg_a) + value(reg_b);
		store(write_reg, result);
	}

	void Addi(int write_reg, int reg_a, int immd)
	{
		int result;
		result = value(reg_a) + immd;
		store(write_reg, result);
	}

	void Sub(int write_reg, int reg_a, int reg_b)
	{
		int result;
		result = value(reg_a) - value(reg_b);
		store(write_reg, result);
	}

	void Subi (int write_reg, int reg_a, int immd)
	{
		int result;
		result = value(reg_a) - immd;
		store(write_reg, result);
	}

	void Mult(int write_reg, int reg_a, int reg_b)
	{
		int result;
		result = value(reg_a) * value(reg_b);
		store(write_reg, result);
	}

	void Multi (int write_reg, int reg_a, int immd)
	{
		int result;
		result = value(reg_a) * immd;
		store(write_reg, result);
	}

	void Div(int write_reg, int reg_a, int reg_b)
	{
		int result;
		result = value(reg_a) / value(reg_b);
		store(write_reg, result);
	}

	void Divi (int write_reg, int reg_a, int immd)
	{
		int result;
		result = value(reg_a) / immd;
		store(write_reg, result);
	}

	void Read_mem (int reg, int memory)
	{
		reg = readWord(memory);
	}

	void Write_mem (int reg, int memory)
	{
		writeWord(memory, reg);
	}

	void Bnez(std::vector &myvector, int target, int reg)
	{
		if (value(reg) == 0)
			jump.jump(myvector, target);
	}

	void Beqz(std::vector &myvector, int target, int reg)
	{
		if (value(reg) != 0)
			jump.jump(myvector, target);
	}

	void Jump(std::vector &myvector, int target)
	{
		//This isnt c++ need to write someting to access vector at target
		//myvector.at(target);
	}
}
*/

#endif