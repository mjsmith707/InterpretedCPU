//
//  Instruction_DIV.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_DIV__
#define __CPUEmulator__Instruction_DIV__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_DIV: public Instruction {
public:
    Instruction_DIV(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_DIV__) */
