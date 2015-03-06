//
//  Instruction_CALL.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_CALL.h"
#include <string>

Instruction_CALL::Instruction_CALL(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_CALL::execute(InstructionContext*& context) {
    context->registerFile[0x1A]->setValue(context->PC->getValue());
    context->PC->setValue(context->r1->getValue());
}

std::string Instruction_CALL::getName() {
    return name;
}

std::string Instruction_CALL::getDescriptor() {
    return descriptor;
}