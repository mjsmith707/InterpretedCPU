//
//  Instruction_SHL.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_SHL.h"
#include <string>

Instruction_SHL::Instruction_SHL(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_SHL::execute(InstructionContext*& context) {
    context->r1->setValue(context->r2->getValue() << context->r3->getValue());
}

std::string Instruction_SHL::getName() {
    return name;
}

std::string Instruction_SHL::getDescriptor() {
    return descriptor;
}