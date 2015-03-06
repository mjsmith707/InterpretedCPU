//
//  Instruction_LA.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_LA.h"
#include <string>

Instruction_LA::Instruction_LA(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_LA::execute(InstructionContext*& context) {
    context->r1->setValue(*context->imm);
}

std::string Instruction_LA::getName() {
    return name;
}

std::string Instruction_LA::getDescriptor() {
    return descriptor;
}