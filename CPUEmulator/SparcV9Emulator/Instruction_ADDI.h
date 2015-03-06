//
//  Instruction_ADDI.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction_ADDI__
#define __CPUEmulator__Instruction_ADDI__

#include "Instruction.h"
#include "InstructionContext.h"

class Instruction_ADDI: public Instruction {
public:
    Instruction_ADDI(unsigned char, std::string, std::string);
    void execute(InstructionContext*&);
    std::string getName();
    std::string getDescriptor();
};

#endif /* defined(__CPUEmulator__Instruction_ADDI__) */
