//
//  Instruction.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/13/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Instruction__
#define __CPUEmulator__Instruction__

#include "Register.h"
#include "InstructionContext.h"
#include <string>

class Instruction {
protected:
    Instruction(unsigned char inopcode, std::string inname, std::string indescriptor) : opcode(inopcode), name(inname), descriptor(indescriptor) {
    };
    
public:
    const unsigned char opcode;
    std::string name;
    std::string descriptor;

    
    virtual void execute(InstructionContext*& context) = 0;
    virtual std::string getName() = 0;
    virtual std::string getDescriptor() = 0;
    
};

#endif /* defined(__CPUEmulator__Instruction__) */
