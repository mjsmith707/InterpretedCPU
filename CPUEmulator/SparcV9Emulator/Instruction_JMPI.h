//
//  Instruction_JMPI.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_JMPI__
#define __CPUEmulator__Instruction_JMPI__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_JMPI: public Instruction {
public:
    Instruction_JMPI(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_JMPI__) */
