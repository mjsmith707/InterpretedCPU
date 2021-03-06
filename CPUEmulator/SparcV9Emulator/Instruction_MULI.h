//
//  Instruction_MULI.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_MULI__
#define __CPUEmulator__Instruction_MULI__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_MULI: public Instruction {
public:
    Instruction_MULI(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_MULI__) */
