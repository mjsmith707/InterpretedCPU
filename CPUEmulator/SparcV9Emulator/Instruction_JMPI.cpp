//
//  Instruction_JMPI.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_JMPI.h"
#include <string>

Instruction_JMPI::Instruction_JMPI(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_JMPI::execute(InstructionContext*& context) {
    context->PC->setValue(*context->jimm);
}

std::string Instruction_JMPI::getName() {
    return name;
}

std::string Instruction_JMPI::getDescriptor() {
    return descriptor;
}