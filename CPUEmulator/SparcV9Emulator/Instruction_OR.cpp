//
//  Instruction_OR.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_OR.h"
#include <string>

Instruction_OR::Instruction_OR(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_OR::execute(InstructionContext*& context) {
    context->r1->setValue(context->r2->getValue() | context->r3->getValue());
}

std::string Instruction_OR::getName() {
    return name;
}

std::string Instruction_OR::getDescriptor() {
    return descriptor;
}