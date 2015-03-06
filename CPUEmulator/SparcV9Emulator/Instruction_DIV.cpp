//
//  Instruction_DIV.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_DIV.h"
#include "Interrupt_DIV0.h"
#include <string>

Instruction_DIV::Instruction_DIV(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_DIV::execute(InstructionContext*& context) {
    if (context->r3->getValue() == 0) {
        throw Interrupt_DIV0();
    }
    context->r1->setValue((int64_t)context->r2->getValue() / (int64_t)context->r3->getValue());
}

std::string Instruction_DIV::getName() {
    return name;
}

std::string Instruction_DIV::getDescriptor() {
    return descriptor;
}