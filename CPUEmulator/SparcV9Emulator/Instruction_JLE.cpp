//
//  Instruction_JLE.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_JLE.h"
#include <string>

Instruction_JLE::Instruction_JLE(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_JLE::execute(InstructionContext*& context) {
    if (context->r1->getValue() <= context->r2->getValue()) {
        context->PC->setValue(*context->imm);
    }
}

std::string Instruction_JLE::getName() {
    return name;
}

std::string Instruction_JLE::getDescriptor() {
    return descriptor;
}