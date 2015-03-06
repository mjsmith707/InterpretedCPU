//
//  Instruction_AND.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_AND.h"
#include <string>

Instruction_AND::Instruction_AND(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_AND::execute(InstructionContext*& context) {
    context->r1->setValue(context->r2->getValue() & context->r3->getValue());
}

std::string Instruction_AND::getName() {
    return name;
}

std::string Instruction_AND::getDescriptor() {
    return descriptor;
}