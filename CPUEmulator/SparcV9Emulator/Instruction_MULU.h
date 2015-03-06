//
//  Instruction_MULU.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_MULU__
#define __CPUEmulator__Instruction_MULU__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_MULU: public Instruction {
public:
    Instruction_MULU(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_MULU__) */
