//
//  Instruction_INT.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_INT__
#define __CPUEmulator__Instruction_INT__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_INT: public Instruction {
public:
    Instruction_INT(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_INT__) */
