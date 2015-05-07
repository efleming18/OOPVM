//Zachary Puster
//Instruction.cpp
#include <iostream>
#include "instruction.hpp"
#include <cstdio>
#include <fstream>
#include <cassert>
#include "machine.hpp"

void movePC(machine* m, int target);


void Add(Instruction i, machine* m)
{
	int result;
    result = m->reg()->value(i.op.ai.reg_a) + m->reg()->value(i.op.ai.reg_b);
    m->reg()->store(i.op.ai.write_reg, result);
}

void Addi(Instruction i, machine* m)
{
	int result;
    result = m->reg()->value(i.op.iai.reg_a) + i.op.iai.immd;
    m->reg()->store(i.op.iai.write_reg, result);
}

void Sub(Instruction i, machine* m)
{
	int result;
    result = m->reg()->value(i.op.ai.reg_a) - m->reg()->value(i.op.ai.reg_b);
    m->reg()->store(i.op.ai.write_reg, result);
}

void Subi(Instruction i, machine* m)
{
	int result;
    result = m->reg()->value(i.op.iai.reg_a) - i.op.iai.immd;
    m->reg()->store(i.op.iai.write_reg, result);
}

void Mult(Instruction i, machine* m)
{
	int result;
    result = m->reg()->value(i.op.ai.reg_a) * m->reg()->value(i.op.ai.reg_b);
    m->reg()->store(i.op.ai.write_reg, result);
}

void Multi(Instruction i, machine* m)
{
	int result;
    result = m->reg()->value(i.op.iai.reg_a) * i.op.iai.immd;
    m->reg()->store(i.op.iai.write_reg, result);
}

void Div(Instruction i, machine* m)
{
	int result;
    result = m->reg()->value(i.op.ai.reg_a) / m->reg()->value(i.op.ai.reg_b);
    m->reg()->store(i.op.ai.write_reg, result);
}

void Divi(Instruction i, machine* m)
{
	int result;
    result = m->reg()->value(i.op.iai.reg_a) / i.op.iai.immd;
    m->reg()->store(i.op.iai.write_reg, result);
}

void Load(Instruction i, machine* m)
{
    i.op.ac.reg = m->mem()->readWord(i.op.ac.memory);
}

void Store(Instruction i, machine* m)
{
    m->mem()->writeWord(i.op.ac.memory, m->reg()->value(i.op.ac.reg));
}

void Bnez(Instruction i, machine* m)
{
    if (m->reg()->value(i.op.br.condition_reg) == 0)
        movePC(m, i.op.br.target);
}

void Beqz(Instruction i, machine* m)
{
    if (m->reg()->value(i.op.br.condition_reg) != 0)
        movePC(m, i.op.br.target);
}

void Jump(Instruction i, machine* m)
{
    movePC(m, i.op.br.target);
}

void movePC(machine *m, int target)
{
    *(m->reg()->pc()) = target;
}


void execute(Instruction i, machine* m)
{
    switch(i.type)
	 {
	 	case Instruction::add:
            Add(i, m);
	 		//std::cout << op.uadd << endl;
	 		break;
	 	case Instruction::addi:
            Addi(i, m);
	 		//std::cout << op.uaddi << endl;
	 		break;
	 	case Instruction::sub:
            Sub(i, m);
	 		//std::cout << op.usub << endl;
	 		break;
	 	case Instruction::subi:
            Subi(i, m);
	 		//std::cout << op.usubi << endl;
	 		break;
	 	case Instruction::mult:
             Mult(i, m);
	 		//std::cout << op.umult << endl;
	 		break;
	 	case Instruction::multi:
            Multi(i, m);
	 		//std::cout << op.umulti << endl;
	 		break;
	 	case Instruction::div:
            Div(i, m);
	 		//std::cout << op.udiv << endl;
	 		break;
	 	case Instruction::divi:
            Divi(i, m);
	 		//std::cout << op.udivi << endl;
	 		break;
	 	case Instruction::load:
            Load(i, m);
	 		//std::cout << op.uload << endl;
	 		break;
	 	case Instruction::store:
            Store(i, m);
	 		//std::cout << op.ustore << endl;
	 		break;
	 	case Instruction::bnez:
            Bnez(i, m);
	 		//std::cout << op.ubnez << endl;
	 		break;
	 	case Instruction::beqz:
            Beqz(i, m);
	 		//std::cout << op.ubeqz << endl;
	 		break;
	 	case Instruction::jump:
            Jump(i, m);
	 		//std::cout << op.ujump << endl;
	 		break;
	 	default:
	 		break;
     }
};


Instruction buildArith(int dest, int a, int b);
Instruction buildImmed(int dest, int a, int i);
Instruction buildAccess(int reg, int mem);
Instruction buildBranch(int cond, int target);
Instruction buildJump(int target);

program build(std::string file)
{
    program retval;

    std::vector<int> data;
    std::ifstream f;
    f.open(file.c_str(), std::ios::binary);
    assert(f.is_open());

    int temp;
    while (!f.eof())
    {
        f.read((char*)&temp, sizeof(int));
        data.push_back(temp);
    }
    data.pop_back();

    for (unsigned int i = 0; i < data.size(); ++i)
    {
        Instruction::instType t = static_cast<Instruction::instType>(data.at(i));
        Instruction inst;

        switch(t)
        {
        case Instruction::add:
        case Instruction::sub:
        case Instruction::mult:
        case Instruction::div:
            inst = buildArith(data.at(i+1), data.at(i+2), data.at(i+3));
            break;
        case Instruction::addi:
        case Instruction::subi:
        case Instruction::multi:
        case Instruction::divi:
            inst = buildImmed(data.at(i+1), data.at(i+2), data.at(i+3));
            break;
        case Instruction::load:
        case Instruction::store:
            inst = buildAccess(data.at(i+1), data.at(i+2));
            break;
        case Instruction::bnez:
        case Instruction::beqz:
            inst = buildBranch(data.at(i+1), data.at(i+2));
            break;
        case Instruction::jump:
            inst = buildJump(data.at(i+1));
            break;
        default:
            assert(false);
            break;
        }

        i += 3;
        inst.type = t;
        retval.push_back(inst);
    }

    return retval;
}

Instruction buildArith(int dest, int a, int b)
{
    Instruction i;
    i.op.ai.write_reg = dest;
    i.op.ai.reg_a = a;
    i.op.ai.reg_b = b;
    return i;
}

Instruction buildImmed(int dest, int a, int i)
{
    Instruction inst;
    inst.op.iai.write_reg = dest;
    inst.op.iai.reg_a = a;
    inst.op.iai.immd = i;
    return inst;
}

Instruction buildAccess(int reg, int mem)
{
    Instruction i;
    i.op.ac.reg = reg;
    i.op.ac.memory = mem;
    return i;
}

Instruction buildBranch(int cond, int target)
{
    Instruction i;
    i.op.br.condition_reg = cond;
    i.op.br.target = target;
    return i;
}

Instruction buildJump(int target)
{
    Instruction i;
    i.op.j.target = target;
    return i;
}
