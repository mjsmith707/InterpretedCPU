//
//  V9CPU.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/13/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__V9CPU__
#define __CPUEmulator__V9CPU__

#include <cstdint>
#include <map>
#include <fstream>
#include <ostream>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <chrono>
#include <queue>
#include <thread>
#include <mutex>
#include "Register.h"
#include "RegisterFile.h"
#include "Instruction.h"
#include "InstructionSet.h"
#include "Memory.h"
#include "IDTEntry.h"
#include "IDTTable.h"
#include "Interrupt_HLT.h"
#include "Interrupt_DIV0.h"
#include "Interrupt_Timer.h"
#include "Interrupt_GPF.h"

#include "Instruction_ADD.h"
#include "Instruction_ADDU.h"
#include "Instruction_ADDI.h"
#include "Instruction_ADDUI.h"
#include "Instruction_SUB.h"
#include "Instruction_SUBU.h"
#include "Instruction_SUBI.h"
#include "Instruction_SUBUI.h"
#include "Instruction_MUL.h"
#include "Instruction_MULU.h"
#include "Instruction_MULI.h"
#include "Instruction_MULUI.h"
#include "Instruction_DIV.h"
#include "Instruction_DIVU.h"
#include "Instruction_DIVI.h"
#include "Instruction_DIVUI.h"
#include "Instruction_AND.h"
#include "Instruction_OR.h"
#include "Instruction_NOT.h"
#include "Instruction_PUSH.h"
#include "Instruction_POP.h"
#include "Instruction_MOV.h"
#include "Instruction_CALL.h"
#include "Instruction_RET.h"
#include "Instruction_INT.h"
#include "Instruction_SETIDT.h"
#include "Instruction_SHL.h"
#include "Instruction_SHR.h"
#include "Instruction_WDT.h"
#include "Instruction_SETINT.h"
#include "Instruction_IRET.h"
#include "Instruction_NOP.h"
#include "Instruction_JMP.h"
#include "Instruction_JMPI.h"
#include "Instruction_JE.h"
#include "Instruction_LA.h"
#include "Instruction_LW.h"
#include "Instruction_SW.h"
#include "Instruction_JNE.h"
#include "Instruction_JL.h"
#include "Instruction_JLE.h"
#include "Instruction_JG.h"
#include "Instruction_JGE.h"
#include "Instruction_HLT.h"

class V9CPU {
private:
    // Special Registers
    Register* PC;
    Register* IR;

    // FDX variables
    InstructionContext* context;
    unsigned char* opcode;
    unsigned char* rs;
    unsigned char* rt;
    unsigned char* rd;
    uint64_t* funct;
    uint64_t* imm;
    uint64_t* jimm;
    
    // Processor State Variables
    bool* kernelmode;
    bool* intenable;
    std::chrono::time_point<std::chrono::high_resolution_clock> timepoint;
    bool* wdtActive;
    std::chrono::nanoseconds wdtLimit;
    int64_t bugcheck;
    
    // Data Tables and Structures
    Memory* mainMemory;
    InstructionSet instructionSet;
    RegisterFile registerFile;
    IDTTable IDT;
    std::queue<Interrupt> INTQueue;
    
    // Interrupt Queue Mutex
    std::mutex IntQueueMutex;
    
    // State Machine Functions
    inline void serviceint(std::ostream&);
    inline void fetch();
    inline void decode();
    inline void execute();
    
public:
    V9CPU();
    bool loadText(uint64_t, std::string&);
    void loadInst(uint64_t, uint64_t);
    void start();
    void sendInterrupt(Interrupt);
    void printRegisterFile(std::ostream&);
    void printStack(std::ostream&);
    void printKStack(std::ostream&);
    
};

#endif /* defined(__CPUEmulator__V9CPU__) */
