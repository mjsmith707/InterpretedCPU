//
//  Instruction_JMP.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_JMP__
#define __CPUEmulator__Instruction_JMP__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_JMP: public Instruction {
public:
    Instruction_JMP(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_JMP__) */
