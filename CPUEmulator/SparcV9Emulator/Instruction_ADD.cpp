//
//  Instruction_ADD.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_ADD.h"
#include <string>

Instruction_ADD::Instruction_ADD(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_ADD::execute(InstructionContext*& context) {
    context->r1->setValue((int64_t)context->r2->getValue() + (int64_t)context->r3->getValue());
}

std::string Instruction_ADD::getName() {
    return name;
}

std::string Instruction_ADD::getDescriptor() {
    return descriptor;
}