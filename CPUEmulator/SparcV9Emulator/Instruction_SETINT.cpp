//
//  Instruction_SETINT.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Instruction_SETINT.h"
#include "IDTEntry.h"
#include "Interrupt_GPF.h"
#include <string>

Instruction_SETINT::Instruction_SETINT(unsigned char inopcode, std::string inname, std::string indescriptor) : Instruction(inopcode, inname, indescriptor) {
}

void Instruction_SETINT::execute(InstructionContext*& context) {
    if (*context->kernelmode) {
        if ((context->r1->getValue() == 0) && (*context->imm == 0)) {
            for (auto entry : context->IDT) {
                entry.second->active = false;
            }
            *context->intenable = false;
        }
        else if ((context->r1->getValue() == 0) && (*context->imm == 1)) {
            for (auto entry : context->IDT) {
                entry.second->active = true;
            }
            *context->intenable = true;
        }
        else {
            auto entry = context->IDT.find(context->r1->getValue());
            if (entry != context->IDT.end()) {
                if (*context->imm == 2) {
                    entry->second->active = false;
                }
                else if (*context->imm == 3) {
                    entry->second->active = true;
                }
            }
        }
    }
    else {
        throw Interrupt_GPF();
    }
}

std::string Instruction_SETINT::getName() {
    return name;
}

std::string Instruction_SETINT::getDescriptor() {
    return descriptor;
}