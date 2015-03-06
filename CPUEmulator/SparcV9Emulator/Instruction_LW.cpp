//
//  Instruction_LW.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_LW.h"
#include <string>

Instruction_LW::Instruction_LW(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_LW::execute(InstructionContext*& context) {
    context->r1->setValue(context->memory->loadWord(context->r2->getValue() + *context->imm));
}

std::string Instruction_LW::getName() {
    return name;
}

std::string Instruction_LW::getDescriptor() {
    return descriptor;
}