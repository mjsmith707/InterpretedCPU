//
//  Instruction_SETUSR.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_SETUSR__
#define __CPUEmulator__Instruction_SETUSR__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_SETUSR: public Instruction {
public:
    Instruction_SETUSR(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_SETUSR__) */
