//
//  Instruction_AND.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_AND__
#define __CPUEmulator__Instruction_AND__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_AND: public Instruction {
public:
    Instruction_AND(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_AND__) */
