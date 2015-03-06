//
//  Instruction_ADDUI.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_ADDUI__
#define __CPUEmulator__Instruction_ADDUI__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_ADDUI: public Instruction {
public:
    Instruction_ADDUI(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_ADDUI__) */
