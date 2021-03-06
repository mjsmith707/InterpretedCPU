//
//  Instruction_ADDI.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_ADDI.h"
#include <string>

Instruction_ADDI::Instruction_ADDI(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_ADDI::execute(InstructionContext*& context) {
    context->r1->setValue((int64_t)context->r2->getValue() + (int64_t)*context->imm);
}

std::string Instruction_ADDI::getName() {
    return name;
}

std::string Instruction_ADDI::getDescriptor() {
    return descriptor;
}