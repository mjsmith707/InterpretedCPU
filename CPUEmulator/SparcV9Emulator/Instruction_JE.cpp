//
//  Instruction_JE.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_JE.h"
#include <string>

Instruction_JE::Instruction_JE(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_JE::execute(InstructionContext*& context) {
    if (context->r1->getValue() == context->r2->getValue()) {
        context->PC->setValue(*context->imm);
    }
}

std::string Instruction_JE::getName() {
    return name;
}

std::string Instruction_JE::getDescriptor() {
    return descriptor;
}