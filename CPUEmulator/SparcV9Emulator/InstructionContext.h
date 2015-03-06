//
//  InstructionContext.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/13/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__InstructionContext__
#define __CPUEmulator__InstructionContext__

#include "Register.h"
#include "RegisterFile.h"
#include "Memory.h"
#include "IDTTable.h"
#include "IDTEntry.h"
#include <cstdint>
#include <chrono>
#include <map>

class InstructionContext {
public:
    Memory* memory;
    RegisterFile& registerFile;
    IDTTable& IDT;
    bool* kernelmode;
    bool* intenable;
    std::chrono::time_point<std::chrono::high_resolution_clock>& timepoint;
    bool* wdtActive;
    std::chrono::nanoseconds& wdtLimit;
    Register* PC;
    Register* r1;
    Register* r2;
    Register* r3;
    uint64_t* funct;
    uint64_t* imm;
    uint64_t* jimm;
    
    InstructionContext(RegisterFile&, IDTTable&, std::chrono::time_point<std::chrono::high_resolution_clock>&, std::chrono::nanoseconds&);
    
    void setWdtActive(bool*&);
    void setKernelMode(bool*&);
    void setIntEnable(bool*&);
    void setPC(Register*&);
    void setMemory(Memory*&);
    
    void setR1(Register*&);
    void setR2(Register*&);
    void setR3(Register*&);
    void setFunct(uint64_t*&);
    void setImm(uint64_t*&);
    void setJimm(uint64_t*&);
};

#endif /* defined(__CPUEmulator__InstructionContext__) */
