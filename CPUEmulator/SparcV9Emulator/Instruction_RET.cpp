//
//  Instruction_RET.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_RET.h"
#include <string>

Instruction_RET::Instruction_RET(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_RET::execute(InstructionContext*& context) {
    context->PC->setValue(context->registerFile[0x1A]->getValue());
}

std::string Instruction_RET::getName() {
    return name;
}

std::string Instruction_RET::getDescriptor() {
    return descriptor;
}