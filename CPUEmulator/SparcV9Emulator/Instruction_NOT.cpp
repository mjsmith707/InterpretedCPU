//
//  Instruction_NOT.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_NOT.h"
#include <string>

Instruction_NOT::Instruction_NOT(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_NOT::execute(InstructionContext*& context) {
    context->r1->setValue(~(context->r2->getValue()));
}

std::string Instruction_NOT::getName() {
    return name;
}

std::string Instruction_NOT::getDescriptor() {
    return descriptor;
}