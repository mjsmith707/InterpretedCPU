//
//  Instruction_JG.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_JG__
#define __CPUEmulator__Instruction_JG__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_JG: public Instruction {
public:
    Instruction_JG(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_JG__) */
