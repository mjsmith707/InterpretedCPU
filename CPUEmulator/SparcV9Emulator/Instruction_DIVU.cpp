//
//  Instruction_DIVU.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_DIVU.h"
#include "Interrupt_DIV0.h"
#include <string>

Instruction_DIVU::Instruction_DIVU(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_DIVU::execute(InstructionContext*& context) {
    if (context->r3->getValue() == 0) {
        throw Interrupt_DIV0();
    }
    context->r1->setValue((uint64_t)context->r2->getValue() / (uint64_t)context->r3->getValue());
}

std::string Instruction_DIVU::getName() {
    return name;
}

std::string Instruction_DIVU::getDescriptor() {
    return descriptor;
}