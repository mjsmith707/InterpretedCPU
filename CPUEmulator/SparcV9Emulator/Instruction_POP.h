//
//  Instruction_POP.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_POP__
#define __CPUEmulator__Instruction_POP__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_POP: public Instruction {
public:
    Instruction_POP(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_POP__) */
