//Zachary Puster
//Instruction.cpp
#include <iostream>
#include "instruction.hpp"
#include <cstdio>
#include "stdio.h"

Instruction i;


void Add()
{
	Instruction i;
	int result;
	result = value(i.op.ai.reg_a) + value(i.op.ai.reg_b);
	store(i.op.ai.write_reg, result);
}

void Addi()
{
	int result;
	result = value(i.op.iai.reg_a) + i.op.iai.immd;
	store(i.op.iai.write_reg, result);
}

void Sub()
{
	int result;
	result = value(i.op.ai.reg_a) - value(i.op.ai.reg_b);
	store(i.op.ai.write_reg, result);	
}

void Subi()
{
	int result;
	result = value(i.op.iai.reg_a) - i.op.iai.immd;
	store(i.op.iai.write_reg, result);	
}

void Mult()
{
	int result;
	result = value(i.op.ia.reg_a) * value(i.op.ia.reg_b);
	store(i.op.ia.write_reg, result);	
}

void Multi()
{
	int result;
	result = value(i.op.iai.reg_a) * i.op.iai.immd;
	store(i.op.iai.write_reg, result);	
}

void Div()
{
	int result;
	result = value(i.op.ai.reg_a) / value(i.op.ai.reg_b);
	store(i.op.ai.write_reg, result);	
}

void Divi()
{
	int result;
	result = value(i.op.iai.reg_a) / i.op.iai.immd;
	store(i.op.iai.write_reg, result);
}

void Load()
{
	i.op.ac.reg = readWord(i.op.ac.memory);
}

void Store()
{
	writeWord(i.op.ac.memory, i.op.ac.reg);
}

void Bnez()
{
	if (value(i.op.br.condition_reg) == 0)
		i.op.j.jump(i.op.br.target);	
}

void Beqz()
{
	if (value(type.br.condition_reg) != 0)
		i.op.j.jump(i.op.br.target);	
}

void Jump()
{
	//This isnt c++ need to write someting to access vector at target
	//myvector.at(target);	
}


int main() {

	fread(file, &i, sizeof(i), 1);


		 switch(i.type)
	 {
	 	case Instruction::add:
	 		Add();
	 		//std::cout << op.uadd << endl;
	 		break;
	 	case Instruction::addi:
	 		Addi();
	 		//std::cout << op.uaddi << endl;
	 		break;
	 	case Instruction::sub:
	 		Sub();
	 		//std::cout << op.usub << endl;
	 		break;
	 	case Instruction::subi:
	 		Subi();
	 		//std::cout << op.usubi << endl;
	 		break;
	 	case Instruction::mult:
	 		 Mult();
	 		//std::cout << op.umult << endl;
	 		break;
	 	case Instruction::multi:
	 		Multi();
	 		//std::cout << op.umulti << endl;
	 		break;
	 	case Instruction::div:
	 		Div();
	 		//std::cout << op.udiv << endl;
	 		break;
	 	case Instruction::divi:
	 		Divi();
	 		//std::cout << op.udivi << endl;
	 		break;
	 	case Instruction::load:
	 		Load();
	 		//std::cout << op.uload << endl;
	 		break;
	 	case Instruction::store:
	 		Store();
	 		//std::cout << op.ustore << endl;
	 		break;
	 	case Instruction::bnez:
	 		Bnez();
	 		//std::cout << op.ubnez << endl;
	 		break;
	 	case Instruction::beqz:
	 		Beqz();
	 		//std::cout << op.ubeqz << endl;
	 		break;
	 	case Instruction::jump:
	 		Jump();
	 		//std::cout << op.ujump << endl;
	 		break;
	 	default:
	 		break;
	 }

	return 0;
};
