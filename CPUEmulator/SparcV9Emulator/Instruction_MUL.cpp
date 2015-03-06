//
//  Instruction_MUL.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_MUL.h"
#include <string>

Instruction_MUL::Instruction_MUL(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_MUL::execute(InstructionContext*& context) {
    context->r1->setValue((int64_t)context->r2->getValue() * (int64_t)context->r3->getValue());
}

std::string Instruction_MUL::getName() {
    return name;
}

std::string Instruction_MUL::getDescriptor() {
    return descriptor;
}