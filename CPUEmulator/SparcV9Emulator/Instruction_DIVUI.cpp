//
//  Instruction_DIVUI.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_DIVUI.h"
#include "Interrupt_DIV0.h"
#include <string>

Instruction_DIVUI::Instruction_DIVUI(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_DIVUI::execute(InstructionContext*& context) {
    if (*context->imm == 0) {
        throw Interrupt_DIV0();
    }
    context->r1->setValue((uint64_t)context->r2->getValue() / (uint64_t)*context->imm);
}

std::string Instruction_DIVUI::getName() {
    return name;
}

std::string Instruction_DIVUI::getDescriptor() {
    return descriptor;
}