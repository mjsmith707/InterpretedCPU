//
//  Instruction_NOP.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_NOP.h"
#include <string>

Instruction_NOP::Instruction_NOP(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_NOP::execute(InstructionContext*& context) {
    // No Operation
}

std::string Instruction_NOP::getName() {
    return name;
}

std::string Instruction_NOP::getDescriptor() {
    return descriptor;
}