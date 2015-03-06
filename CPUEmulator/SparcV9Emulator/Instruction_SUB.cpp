//
//  Instruction_SUB.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_SUB.h"
#include <string>

Instruction_SUB::Instruction_SUB(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_SUB::execute(InstructionContext*& context) {
    context->r1->setValue((int64_t)context->r2->getValue() - (int64_t)context->r3->getValue());
}

std::string Instruction_SUB::getName() {
    return name;
}

std::string Instruction_SUB::getDescriptor() {
    return descriptor;
}