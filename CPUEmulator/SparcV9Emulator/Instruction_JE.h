//
//  Instruction_JE.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_JE__
#define __CPUEmulator__Instruction_JE__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_JE: public Instruction {
public:
    Instruction_JE(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_JE__) */
