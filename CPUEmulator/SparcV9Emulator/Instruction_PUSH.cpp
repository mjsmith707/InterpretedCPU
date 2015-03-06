//
//  Instruction_PUSH.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_PUSH.h"
#include <string>

Instruction_PUSH::Instruction_PUSH(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_PUSH::execute(InstructionContext*& context) {
    if (*context->kernelmode) {
        context->memory->storeWord(context->registerFile[0x1C]->getValue(), context->r1->getValue());
        context->registerFile[0x1C]->setValue(context->registerFile[0x1C]->getValue() + 8);
    }
    else {
        context->memory->storeWord(context->registerFile[0x1A]->getValue(), context->r1->getValue());
        context->registerFile[0x1A]->setValue(context->registerFile[0x1A]->getValue() + 8);
    }
}

std::string Instruction_PUSH::getName() {
    return name;
}

std::string Instruction_PUSH::getDescriptor() {
    return descriptor;
}