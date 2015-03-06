//
//  Instruction_SW.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_SW.h"
#include <string>

Instruction_SW::Instruction_SW(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_SW::execute(InstructionContext*& context) {
    context->memory->storeWord(context->r2->getValue() + *context->imm, context->r1->getValue());
}

std::string Instruction_SW::getName() {
    return name;
}

std::string Instruction_SW::getDescriptor() {
    return descriptor;
}