//
//  Instruction_SHR.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_SHR.h"
#include <string>

Instruction_SHR::Instruction_SHR(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_SHR::execute(InstructionContext*& context) {
    context->r1->setValue(context->r2->getValue() >> context->r3->getValue());
}

std::string Instruction_SHR::getName() {
    return name;
}

std::string Instruction_SHR::getDescriptor() {
    return descriptor;
}