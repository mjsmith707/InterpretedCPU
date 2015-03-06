//
//  Instruction_INT.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_INT.h"
#include <string>

Instruction_INT::Instruction_INT(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_INT::execute(InstructionContext*& context) {
    throw Interrupt(*context->imm);
}

std::string Instruction_INT::getName() {
    return name;
}

std::string Instruction_INT::getDescriptor() {
    return descriptor;
}