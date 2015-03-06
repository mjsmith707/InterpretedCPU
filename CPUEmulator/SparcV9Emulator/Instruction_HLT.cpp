//
//  Instruction_HLT.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_HLT.h"
#include "Interrupt_HLT.h"
#include "interrupt_GPF.h"
#include <string>

Instruction_HLT::Instruction_HLT(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_HLT::execute(InstructionContext*& context) {
    if (*context->kernelmode) {
        throw Interrupt_HLT();
    }
    else {
        throw Interrupt_GPF();
    }
}

std::string Instruction_HLT::getName() {
    return name;
}

std::string Instruction_HLT::getDescriptor() {
    return descriptor;
}