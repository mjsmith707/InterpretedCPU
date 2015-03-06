//
//  Instruction_DIVI.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_DIVI.h"
#include "Interrupt_DIV0.h"
#include <string>

Instruction_DIVI::Instruction_DIVI(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_DIVI::execute(InstructionContext*& context) {
    if (*context->imm == 0) {
        throw Interrupt_DIV0();
    }
    context->r1->setValue((int64_t)context->r2->getValue() / (int64_t)*context->imm);
}

std::string Instruction_DIVI::getName() {
    return name;
}

std::string Instruction_DIVI::getDescriptor() {
    return descriptor;
}