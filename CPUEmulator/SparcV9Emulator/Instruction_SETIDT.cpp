//
//  Instruction_SETIDT.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_SETIDT.h"
#include "IDTEntry.h"
#include "Interrupt_GPF.h"
#include <string>

Instruction_SETIDT::Instruction_SETIDT(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_SETIDT::execute(InstructionContext*& context) {
    if (*context->kernelmode) {
        IDTEntry* newidt = new IDTEntry();
        newidt->active = false;
        newidt->address = context->r1->getValue();
        context->IDT.emplace(*context->imm, newidt);
    }
    else {
        throw Interrupt_GPF();
    }
}

std::string Instruction_SETIDT::getName() {
    return name;
}

std::string Instruction_SETIDT::getDescriptor() {
    return descriptor;
}