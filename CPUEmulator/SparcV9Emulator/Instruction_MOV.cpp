//
//  Instruction_MOV.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_MOV.h"
#include <string>

Instruction_MOV::Instruction_MOV(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_MOV::execute(InstructionContext*& context) {
    context->r1->setValue(context->r2->getValue());
}

std::string Instruction_MOV::getName() {
    return name;
}

std::string Instruction_MOV::getDescriptor() {
    return descriptor;
}