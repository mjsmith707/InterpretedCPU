//
//  Instruction_IRET.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/18/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_IRET__
#define __CPUEmulator__Instruction_IRET__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_IRET: public Instruction {
public:
    Instruction_IRET(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_IRET__) */
