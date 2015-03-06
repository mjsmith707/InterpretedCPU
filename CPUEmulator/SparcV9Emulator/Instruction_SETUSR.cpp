//
//  Instruction_SETUSR.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_SETUSR.h"
#include "Interrupt_GPF.h"
#include <string>

Instruction_SETUSR::Instruction_SETUSR(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_SETUSR::execute(InstructionContext*& context) {
    if (*context->kernelmode) {
        *context->kernelmode = false;
    }
    else {
        throw Interrupt_GPF();
    }
}

std::string Instruction_SETUSR::getName() {
    return name;
}

std::string Instruction_SETUSR::getDescriptor() {
    return descriptor;
}