#include "instruction.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int parseRegister(std::string currentInstruction, int &stringPointer){
	std::string reg;
	//This should parse out r/R and just give a number
	while(currentInstruction[stringPointer] != ',' && stringPointer != *currentInstruction.end()){
		if(currentInstruction[stringPointer] != 'r' && currentInstruction[stringPointer] != 'R'){
			reg += currentInstruction[stringPointer++];
		}else{stringPointer++;}//end if
	}//end while
	//Incremement pointer past ','
	stringPointer += 2;
	//Remove any spaces
	while(currentInstruction[stringPointer] == ' ' && stringPointer != *currentInstruction.end()){
		stringPointer++;
	}
	//std::cout << reg << std::endl;
	return stoi(reg);
}

int parseImmediate(std::string currentInstruction, int &stringPointer){
	std::string imm;
	int returnValue;
	//immediates are 8 chars long, plus 0x for a total of 10 chars
	for(int i = 0; i < 10; i++){
		imm += currentInstruction[stringPointer++];
		if(stringPointer == *currentInstruction.end()){
			break;
		}
	}

	//Case for address
	if(currentInstruction[stringPointer] == ','){
		stringPointer++;
	}
	while(currentInstruction[stringPointer] == ' ' && stringPointer != *currentInstruction.end()){
		stringPointer++;
	}
	//std::cout << "imm = " << imm << std::endl;
	std::stringstream ss;
	ss << std::hex << imm;
    ss >> returnValue;
	return static_cast<int>(returnValue);
}

int main(int argc, char* argv[]){

	std::cout << std::endl;
	std::ifstream asmFile;
	char charInstruction[256];
	std::vector<std::string> instructionVector;
	Program instructionList;
	std::string currentInstruction;
	asmFile.open(argv[1]);

	if(asmFile.is_open()){
		//Read in all instructions
		while(!asmFile.eof()){
			asmFile.getline(charInstruction,256);
			instructionVector.push_back(charInstruction);
		}

		//Need to convert vector of strings to vector of instructions
		for(int i = 0; i < instructionVector.size(); i++){
			//Get current Instruction from vector
			currentInstruction = instructionVector[i];
			std::cout << currentInstruction << std::endl;
			int stringPointer = 0;
			std::string instructionType;
			while(currentInstruction[stringPointer] != ' '){
				instructionType += currentInstruction[stringPointer++];
			}
			//Incrememnt pointer to get to first argument
			stringPointer++;
			Instruction::type ofInstruction;
			if(instructionType == "Add"){
				ofInstruction = Instruction::add;
			}else if(instructionType == "Addi"){
				ofInstruction = Instruction::addi;
			}else if(instructionType == "Mult"){
				ofInstruction = Instruction::mult;
			}else if(instructionType == "Multi"){
				ofInstruction = Instruction::multi;
			}else if(instructionType == "Store"){
				ofInstruction = Instruction::store;
			}else if(instructionType == "Load"){
				ofInstruction = Instruction::load;
			}else{
				std::cout << "Unknown Type: " << instructionType << std::endl;
			}
			std::cout << instructionType << " " << ofInstruction << std::endl;
			//Now that we know the instruction type, need to get args
			int out, in1, in2; //all registers
			switch(ofInstruction){
				case Instruction::add:
					//This has 3 args, parse them
					out = parseRegister(currentInstruction,stringPointer);
					in1 = parseRegister(currentInstruction,stringPointer);
					in2 = parseRegister(currentInstruction,stringPointer);
					std::cout << out << std::endl;
					std::cout << in1 << std::endl;
					std::cout << in2 << std::endl;
					break;
				case Instruction::addi:
					//This has 3 args, parse them
					out = parseRegister(currentInstruction,stringPointer);
					in1 = parseRegister(currentInstruction,stringPointer);
					in2 = parseImmediate(currentInstruction,stringPointer);
					std::cout << out << std::endl;
					std::cout << in1 << std::endl;
					std::cout << in2 << std::endl;
					break;
					break;
				case Instruction::mult:
					//This has 3 args, parse them
					out = parseRegister(currentInstruction,stringPointer);
					in1 = parseRegister(currentInstruction,stringPointer);
					in2 = parseRegister(currentInstruction,stringPointer);
					std::cout << out << std::endl;
					std::cout << in1 << std::endl;
					std::cout << in2 << std::endl;
					break;
				case Instruction::multi:
					//This has 3 args, parse them
					out = parseRegister(currentInstruction,stringPointer);
					in1 = parseRegister(currentInstruction,stringPointer);
					in2 = parseImmediate(currentInstruction,stringPointer);
					std::cout << out << std::endl;
					std::cout << in1 << std::endl;
					std::cout << in2 << std::endl;
					break;
				case Instruction::store:
					out = parseImmediate(currentInstruction,stringPointer);
					in1 = parseRegister(currentInstruction,stringPointer);
					std::cout << out << std::endl;
					std::cout << in1 << std::endl;
					break;
				default:
					std::cout << "Unknown type of instruction..." << std::endl;
					break;
			}
			std::cout << std::endl;
		}
		
	}else{
		std::cout << "Error opening file " << argv[1] << "..." << std::endl;
	}

	//always close file
	asmFile.close();
	std::cout << std::endl;
	return 0;
}//end main