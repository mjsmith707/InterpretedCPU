//
//  Instruction_WDT.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_WDT.h"
#include "Interrupt_GPF.h"
#include <string>

Instruction_WDT::Instruction_WDT(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_WDT::execute(InstructionContext*& context) {
    if (*context->kernelmode) {
        if (context->r1->getValue() == 0) {
            auto entry = context->IDT.find(0);
            if (entry != context->IDT.end()) {
                *context->wdtActive = false;
                entry->second->active = false;
            }
        }
        else {
            auto entry = context->IDT.find(0);
            if (entry != context->IDT.end()) {
                *context->wdtActive = true;
                entry->second->active = true;
                context->wdtLimit = std::chrono::nanoseconds(context->r1->getValue()*1000000);
                context->timepoint = std::chrono::high_resolution_clock::now();
            }
        }
    }
    else {
        throw Interrupt_GPF();
    }
}

std::string Instruction_WDT::getName() {
    return name;
}

std::string Instruction_WDT::getDescriptor() {
    return descriptor;
}