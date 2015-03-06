//
//  InstructionContext.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/13/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "InstructionContext.h"

InstructionContext::InstructionContext(RegisterFile& regfile, IDTTable& idttable, std::chrono::time_point<std::chrono::high_resolution_clock>& wdttimepoint, std::chrono::nanoseconds& wdtlimit) : registerFile(regfile), IDT(idttable), timepoint(wdttimepoint), wdtLimit(wdtlimit) {
    
}

void InstructionContext::setKernelMode(bool*& mode) {
    kernelmode = mode;
}

void InstructionContext::setIntEnable(bool*& mode) {
    intenable = mode;
}

void InstructionContext::setWdtActive(bool*& mode) {
    wdtActive = mode;
}

void InstructionContext::setMemory(Memory*& mem) {
    memory = mem;
}

void InstructionContext::setPC(Register*& pc) {
    PC = pc;
}

void InstructionContext::setR1(Register*& R1) {
    r1 = R1;
}

void InstructionContext::setR2(Register*& R2) {
    r2 = R2;
}

void InstructionContext::setR3(Register*& R3) {
    r3 = R3;
}

void InstructionContext::setFunct(uint64_t*& FUNCT) {
    funct = FUNCT;
}

void InstructionContext::setImm(uint64_t*& IMM) {
    imm = IMM;
}

void InstructionContext::setJimm(uint64_t*& JIMM) {
    jimm = JIMM;
}

