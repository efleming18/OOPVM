//Zachary Puster
//Instruction.cpp
#include <iostream>
#include "instruction.hpp"
#include <cstdio>
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
    m->mem()->writeWord(i.op.ac.memory, i.op.ac.reg);
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
