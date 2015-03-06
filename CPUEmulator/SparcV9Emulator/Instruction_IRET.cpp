//
//  Instruction_IRET.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/18/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_IRET.h"
#include "Interrupt_GPF.h"
#include <string>

Instruction_IRET::Instruction_IRET(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {

}

void Instruction_IRET::execute(InstructionContext*& context) {
    if (*context->kernelmode) {
        context->registerFile[0x1C]->setValue(context->registerFile[0x1C]->getValue() - 8);
        context->registerFile[0x1F]->setValue((context->memory->loadWord(context->registerFile[0x1C]->getValue())));
        context->PC->setValue((context->memory->loadWord(context->registerFile[0x1C]->getValue())));
    }
    else {
        throw Interrupt_GPF();
    }
}

std::string Instruction_IRET::getName() {
    return name;
}

std::string Instruction_IRET::getDescriptor() {
    return descriptor;
}