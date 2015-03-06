//
//  Instruction_ADD.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_ADD__
#define __CPUEmulator__Instruction_ADD__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_ADD: public Instruction {
public:
    Instruction_ADD(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_ADD__) */
