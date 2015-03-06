//
//  Instruction_PUSH.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_PUSH__
#define __CPUEmulator__Instruction_PUSH__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_PUSH: public Instruction {
public:
    Instruction_PUSH(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_PUSH__) */
