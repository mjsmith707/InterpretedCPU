//
//  Instruction_ADDUI.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_ADDUI.h"
#include <string>

Instruction_ADDUI::Instruction_ADDUI(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_ADDUI::execute(InstructionContext*& context) {
    context->r1->setValue((uint64_t)context->r2->getValue() + (uint64_t)*context->imm);
}

std::string Instruction_ADDUI::getName() {
    return name;
}

std::string Instruction_ADDUI::getDescriptor() {
    return descriptor;
}