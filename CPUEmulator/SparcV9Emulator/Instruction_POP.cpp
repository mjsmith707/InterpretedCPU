//
//  Instruction_POP.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_POP.h"
#include <string>

Instruction_POP::Instruction_POP(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_POP::execute(InstructionContext*& context) {
    if (*context->kernelmode) {
        context->registerFile[0x1C]->setValue(context->registerFile[0x1C]->getValue() - 8);
        context->r1->setValue(context->memory->loadWord(context->registerFile[0x1C]->getValue()));
        
    }
    else {
        context->registerFile[0x1A]->setValue(context->registerFile[0x1A]->getValue() - 8);
        context->r1->setValue(context->memory->loadWord(context->registerFile[0x1A]->getValue()));
    }
}

std::string Instruction_POP::getName() {
    return name;
}

std::string Instruction_POP::getDescriptor() {
    return descriptor;
}