//
//  Instruction_SUBU.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_SUBU__
#define __CPUEmulator__Instruction_SUBU__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_SUBU: public Instruction {
public:
    Instruction_SUBU(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_SUBU__) */
