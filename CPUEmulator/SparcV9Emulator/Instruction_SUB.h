//
//  Instruction_SUB.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_SUB__
#define __CPUEmulator__Instruction_SUB__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_SUB: public Instruction {
public:
    Instruction_SUB(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_SUB__) */
