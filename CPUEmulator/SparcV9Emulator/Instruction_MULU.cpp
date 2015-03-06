//
//  Instruction_MULU.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_MULU.h"
#include <string>

Instruction_MULU::Instruction_MULU(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_MULU::execute(InstructionContext*& context) {
    context->r1->setValue((uint64_t)context->r2->getValue() * (uint64_t)context->r3->getValue());
}

std::string Instruction_MULU::getName() {
    return name;
}

std::string Instruction_MULU::getDescriptor() {
    return descriptor;
}