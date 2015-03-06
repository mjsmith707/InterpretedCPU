//
//  Instruction_JMP.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_JMP.h"
#include <string>

Instruction_JMP::Instruction_JMP(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_JMP::execute(InstructionContext*& context) {
    context->PC->setValue(context->r1->getValue());
}

std::string Instruction_JMP::getName() {
    return name;
}

std::string Instruction_JMP::getDescriptor() {
    return descriptor;
}