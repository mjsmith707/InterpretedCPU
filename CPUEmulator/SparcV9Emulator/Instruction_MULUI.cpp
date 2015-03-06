//
//  Instruction_MULUI.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_MULUI.h"
#include <string>

Instruction_MULUI::Instruction_MULUI(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_MULUI::execute(InstructionContext*& context) {
    context->r1->setValue((uint64_t)context->r2->getValue() * (uint64_t)*context->imm);
}

std::string Instruction_MULUI::getName() {
    return name;
}

std::string Instruction_MULUI::getDescriptor() {
    return descriptor;
}