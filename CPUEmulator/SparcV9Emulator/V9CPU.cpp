//
//  V9CPU.cpp
//  CPUEmulator <- Optimistic Project Name
//
//  Created by Matt Smith on 11/13/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//
/*
 IDT Map
 0 - Watchdog Timer
 1 - Halt
 2 - Double fault
 3 - Alignment Error
 4 - Divide by zero
 5 - General Protection Fault
 */

#include "V9CPU.h"

V9CPU::V9CPU() {
    PC = new Register((uint64_t)0x0000000010010000);
    IR = new Register();
    kernelmode = new bool();
    *kernelmode = true;
    intenable = new bool();
    *intenable = false;
    mainMemory = new Memory(16);
    opcode = new unsigned char();
    rs = new unsigned char();
    rt = new unsigned char();
    rd = new unsigned char();
    funct = new uint64_t();
    imm = new uint64_t();
    jimm = new uint64_t();
    wdtActive = new bool();
    *wdtActive = false;
    
    context = new InstructionContext(registerFile, IDT, timepoint, wdtLimit);
    context->setPC(PC);
    context->setKernelMode(kernelmode);
    context->setIntEnable(intenable);
    context->setWdtActive(wdtActive);
    context->setMemory(mainMemory);
    
    registerFile[0] = new Register(true);
    registerFile[1] = new Register();
    registerFile[2] = new Register();
    registerFile[3] = new Register();
    registerFile[4] = new Register();
    registerFile[5] = new Register();
    registerFile[6] = new Register();
    registerFile[7] = new Register();
    registerFile[8] = new Register();
    registerFile[9] = new Register();
    registerFile[10] = new Register();
    registerFile[11] = new Register();
    registerFile[12] = new Register();
    registerFile[13] = new Register();
    registerFile[14] = new Register();
    registerFile[15] = new Register();
    registerFile[16] = new Register();
    registerFile[17] = new Register();
    registerFile[18] = new Register();
    registerFile[19] = new Register();
    registerFile[20] = new Register();
    registerFile[21] = new Register();
    registerFile[22] = new Register();
    registerFile[23] = new Register();
    registerFile[24] = new Register();
    registerFile[25] = new Register();
    registerFile[26] = new Register((uint64_t)0x1000000000000000);   // User Stack Pointer
    registerFile[27] = new Register((uint64_t)0x1000000000000000);   // User Frame Pointer
    registerFile[28] = new Register((uint64_t)0xA000000000000000);   // Global Stack Pointer
    registerFile[29] = new Register((uint64_t)0xA000000000000000);   // Global Frame Pointer
    registerFile[30] = new Register();  // User Return Address
    registerFile[31] = new Register();  // Global Return Address
    
    instructionSet[0x0] = new Instruction_ADD(0x0, "Signed Addition", "r1 = r2 + r3");
    instructionSet[0x1] = new Instruction_ADDI(0x1, "Signed Addition Immediate", "r1 = r2 + imm");
    instructionSet[0x2] = new Instruction_ADDU(0x2, "Unsigned Addition", "r1 = r2 + r3");
    instructionSet[0x3] = new Instruction_ADDUI(0x3, "Unsigned Addition Immediate", "r1 = r2 + imm");
    instructionSet[0x4] = new Instruction_SUB(0x4, "Signed Subtraction", "r1 = r2 - r3");
    instructionSet[0x5] = new Instruction_SUBI(0x5, "Signed Subtraction Immediate", "r1 = r2 - imm");
    instructionSet[0x6] = new Instruction_SUBU(0x6, "Unsigned Subtraction", "r1 = r2 - r3");
    instructionSet[0x7] = new Instruction_SUBUI(0x7, "Unsigned Subtraction Immediate", "r1 = r2 - imm");
    instructionSet[0x8] = new Instruction_MUL(0x8, "Signed Integer Multiplication", "r1 = r2 * r3");
    instructionSet[0x9] = new Instruction_MULI(0x9, "Signed Integer Multiplication Immediate", "r1 = r2 * imm");
    instructionSet[0xA] = new Instruction_MULU(0xA, "Unsigned Integer Multiplication", "r1 = r2 * r3");
    instructionSet[0xB] = new Instruction_MULUI(0xB, "Unsigned Integer Multiplication Immediate", "r1 = r2 * imm");
    instructionSet[0xC] = new Instruction_DIV(0xC, "Signed Integer Division", "r1 = r2 / r3");
    instructionSet[0xD] = new Instruction_DIVI(0xD, "Signed Integer Division Immediate", "r1 = r2 / imm");
    instructionSet[0xE] = new Instruction_DIVU(0xE, "Unsigned Integer Division", "r1 = r2 / r3");
    instructionSet[0xF] = new Instruction_DIVUI(0xF, "Unsigned Integer Division Immediate", "r1 = r2 / imm");
    instructionSet[0x10] = new Instruction_AND(0x10, "Bitwise AND", "r1 = r2&r3");
    instructionSet[0x11] = new Instruction_OR(0x11, "Bitwise OR", "r1 = r2|r3");
    instructionSet[0x12] = new Instruction_NOT(0x12, "Btwise Negation", "r1 = ~r2");
    instructionSet[0x13] = new Instruction_PUSH(0x13, "Push Register to Stack", "MEM[sp] = r1, sp+8");
    instructionSet[0x14] = new Instruction_POP(0x14, "Pop Top of Stack", "r1 = MEM[sp], sp-8");
    instructionSet[0x15] = new Instruction_MOV(0x15, "Copy Register Contents", "r1 = r2");
    instructionSet[0x16] = new Instruction_CALL(0x16, "Call Function", "ra = pc, pc = r1, ");
    instructionSet[0x17] = new Instruction_RET(0x17, "Return to caller", "pc = ra");
    instructionSet[0x18] = new Instruction_INT(0x18, "Trigger Interrupt", "int = imm");
    instructionSet[0x19] = new Instruction_SETIDT(0x19, "Set IDT Address", "IDT[imm] = r1");
    instructionSet[0x1A] = new Instruction_SHL(0x1A, "Shift Left", "r1 = r2 << r3");
    instructionSet[0x1B] = new Instruction_SHR(0x1B, "Shift Right", "r1 = r2 >> r3");
    instructionSet[0x1C] = new Instruction_WDT(0x1C, "Toggle Watchdog", "r1==0 : wdtactive = false ? wdtactive = true, wdtlimit(ms) = r1");
    instructionSet[0x1D] = new Instruction_SETINT(0x1D, "Set Interrupt Active State", "if (r1=0 && imm=0) disable all ints, else if (r1=0, && imm=1), enable all ints, else if (imm = 2) disable IDT[r1], else if (imm = 3), enable IDT[r1])");
    instructionSet[0x1E] = new Instruction_IRET(0x1E, "Pop TRA from stack and Return from Interrupt Vector", "%tra = %gsp-8, %gsp = %gsp-8, %pc = %tra");
    
    instructionSet[0x1F] = new Instruction_NOP(0x1F, "No Operation", "Does exactly nothing");
    instructionSet[0x20] = new Instruction_JMP(0x20, "Unconditional Jump", "jmp r1");
    instructionSet[0x21] = new Instruction_JMPI(0x21, "Unconditional Jump from Immediate", "jmpi jimm");
    instructionSet[0x22] = new Instruction_JE(0x22, "Jump if Equal", "if (r1==r2) jmp imm");
    instructionSet[0x23] = new Instruction_LA(0x23, "Load Address", "r1 = imm");
    instructionSet[0x24] = new Instruction_LW(0x24, "Load Word", "r1 = MEM[r2+imm]");
    instructionSet[0x25] = new Instruction_SW(0x25, "Store Word", "MEM[r2+imm] = r1");
    instructionSet[0x26] = new Instruction_JNE(0x26, "Jump if Not Equal", "if (r1!=r2) jmp imm");
    instructionSet[0x27] = new Instruction_JL(0x27, "Jump if Less Than", "if (r1<r2) jmp imm");
    instructionSet[0x28] = new Instruction_JLE(0x28, "Jump if Less Than Equal", "if (r1<=r2) jmp imm");
    instructionSet[0x29] = new Instruction_JG(0x29, "Jump if Greater Than", "if (r1>r2) jmp imm");
    instructionSet[0x2A] = new Instruction_JGE(0x2A, "Jump if Greater Than Equal", "if (r1>=r2) jmp imm");
    instructionSet[0x3F] = new Instruction_HLT(0x3F, "CPU HALT", "Shuts down processor");
}

inline void V9CPU::serviceint(std::ostream& output) {
    if (!*intenable) {
        return;
    }
    else if (!INTQueue.empty()) {
        std::unique_lock<std::mutex> queueLock(IntQueueMutex);
        auto interrupt = INTQueue.front();
        if (interrupt.getType() == 1) {
            throw Interrupt_HLT();
        }
        auto handler = IDT.find(interrupt.getType());
        if (handler == IDT.end()) {
            // Double Fault
            INTQueue.pop();
            queueLock.unlock();
            handler = IDT.find(2);
            if (handler == IDT.end()) {
                // Triple Fault
                throw std::runtime_error("Triple Fault");
            }
            *kernelmode = true;
            *intenable = false;
            registerFile[0x1F]->setValue(PC->getValue());
            PC->setValue(handler->second->address);
        }
        else if (handler->second->active) {
            output << "=Interrupt=" << std::endl << "int = " << interrupt.getType() << std::endl
            << "PC =     0x"  << std::setfill('0') << std::setw(16) << std::hex << PC->getValue() << std::endl << "IR =     0x"  << std::setfill('0') << std::setw(16) << std::hex << IR->getValue() << std::endl << "tra = " << std::setfill('0') << std::setw(16) << std::hex << PC->getValue() << std::endl;
            INTQueue.pop();
            queueLock.unlock();
            *kernelmode = true;
            *intenable = false;
            registerFile[0x1F]->setValue(PC->getValue());
            PC->setValue(handler->second->address);
        }
        else {
            // Deactivated Interrupt
            INTQueue.pop();
            queueLock.unlock();
        }
    }
}

inline void V9CPU::fetch() {
    IR->setValue(mainMemory->loadWord(PC->getValue()));
    PC->setValue(PC->getValue() + 8);
    if (bugcheck == PC->getValue()) {
        throw std::runtime_error("Infinite Loop Detected");
    }
}

inline void V9CPU::decode() {
    *opcode = ((IR->getValue() & 0xFC00000000000000) >> 58);
    *rs = ((IR->getValue() & 0x3E0000000000000) >> 53);
    *rt = ((IR->getValue() & 0x1F000000000000) >> 48);
    *rd = ((IR->getValue() & 0xF80000000000) >> 43);
    *funct = (IR->getValue() & 0x7FFFFFFFFFF);
    *imm = ((IR->getValue() & 0xFFFFFFFFFFFF));
    *jimm = ((IR->getValue() & 0x3FFFFFFFFFFFFFF));
}

inline void V9CPU::execute() {
    context->setR1(registerFile[*rs]);
    context->setR2(registerFile[*rt]);
    context->setR3(registerFile[*rd]);
    context->setFunct(funct);
    context->setImm(imm);
    context->setJimm(jimm);
    bugcheck = PC->getValue();
    instructionSet[*opcode]->execute(context);
}

void V9CPU::start() {
    //std::ofstream output;
    //output.open("/Users/msmith/Desktop/output.txt", std::ios_base::out | std::ios_base::trunc);
    std::ostream& output = std::cout;
    uint64_t executionCount = 0;
    for (;;) {
        try {
            if (*wdtActive) {
                std::chrono::time_point<std::chrono::high_resolution_clock> tdelta = std::chrono::high_resolution_clock::now();
                if (std::chrono::duration_cast<std::chrono::nanoseconds>(tdelta-timepoint).count() > wdtLimit.count()) {
                    *wdtActive = false;
                    throw Interrupt_Timer();
                }
            }
            serviceint(output);
            output << "=Fetch=" << std::endl;
            fetch();
            output << "PC =     0x"  << std::setfill('0') << std::setw(16) << std::hex << PC->getValue() << std::endl << "IR =     0x"  << std::setfill('0') << std::setw(16) << std::hex << IR->getValue() << std::endl << "=Decode=" << std::endl;
            decode();
            output << "opcode = 0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned short)*opcode << std::endl << "rs =     0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned short)*rs << std::endl << "rt =     0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned short)*rt << std::endl << "rd =     0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned short)*rd << std::endl << "imm =    0x" << std::setfill('0') << std::setw(16) << std::hex << *imm << std::endl << "jimm =   0x" << std::setfill('0') << std::setw(16) << std::hex << *jimm << std::endl << "=Execute=" << std::endl;
            execute();
            executionCount++;
        }
        catch (const Interrupt_HLT hlt) {
            output << "CPU HALT" << std::endl;
            output << "Executed Instructions = " << std::dec << executionCount << std::endl;
            output << "PC =     0x"  << std::setfill('0') << std::setw(16) << std::hex << PC->getValue() << std::endl << "IR =     0x"  << std::setfill('0') << std::setw(16) << std::hex << IR->getValue() << std::endl << "=Decode=" << std::endl;
            output << "opcode = 0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned short)*opcode << std::endl << "rs =     0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned short)*rs << std::endl << "rt =     0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned short)*rt << std::endl << "rd =     0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned short)*rd << std::endl << "imm =    0x" << std::setfill('0') << std::setw(16) << std::hex << *imm << std::endl << "jimm =   0x" << std::setfill('0') << std::setw(16) << std::hex << *jimm << std::endl;
            return;
        }
        catch (Interrupt interrupt) {
            std::unique_lock<std::mutex> queueLock(IntQueueMutex);
            INTQueue.push(interrupt);
            queueLock.unlock();
            continue;
        }
        catch (const std::runtime_error e) {
            output << "Caught runtime_error. Simulation terminated." << std::endl;
            output << "Error: " << e.what() << std::endl;
            output << "Executed Instructions = " << std::dec << executionCount << std::endl;
            output << "PC =     0x"  << std::setfill('0') << std::setw(16) << std::hex << PC->getValue() << std::endl << "IR =     0x"  << std::setfill('0') << std::setw(16) << std::hex << IR->getValue() << std::endl << "=Decode=" << std::endl;
            output << "opcode = 0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned short)*opcode << std::endl << "rs =     0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned short)*rs << std::endl << "rt =     0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned short)*rt << std::endl << "rd =     0x" << std::setfill('0') << std::setw(2) << std::hex << (unsigned short)*rd << std::endl << "imm =    0x" << std::setfill('0') << std::setw(16) << std::hex << *imm << std::endl << "jimm =   0x" << std::setfill('0') << std::setw(16) << std::hex << *jimm << std::endl;
            return;
        }
    }
}

void V9CPU::sendInterrupt(Interrupt interrupt) {
    std::lock_guard<std::mutex> queueLock(IntQueueMutex);
    INTQueue.push(interrupt);
}

union int64t_char {
    char bytes[8];
    uint64_t word;
};

bool V9CPU::loadText(uint64_t baseaddr, std::string& filename) {
    std::ifstream handle;
    handle.open(filename, std::ios_base::in | std::ios_base::binary);
    if (!handle.is_open()) {
        return false;
    }
    int64_t offset = 0x8;
    
    std::vector<uint64_t> buffer;
    int64t_char temp;
    while (!handle.eof()) {
        for (int i=0; i<8; i++) {
            temp.bytes[i] = handle.get();
        }
        buffer.push_back(temp.word);
    }
    
    for (size_t i=0; i<buffer.size()-1; i++) {
        mainMemory->storeWord(baseaddr+(i*offset), buffer.at(i));
    }
    handle.close();
    
    return true;
}

void V9CPU::loadInst(uint64_t address, uint64_t instruction) {
    mainMemory->storeWord(address, instruction);
}

void V9CPU::printRegisterFile(std::ostream& out) {
    out << "=Register File=" << std::endl;
    for (size_t i=0; i<registerFile.size(); i++) {
        out << "r[" << i << "] : 0x" << std::setfill('0') << std::setw(16) << std::hex << registerFile.at(i)->getValue() << std::endl;
    }
}

void V9CPU::printKStack(std::ostream& out) {
    for (uint64_t i = registerFile[0x1D]->getValue(); i < registerFile[0x1C]->getValue(); i+=8) {
        out << "[0x" << i << "] : 0x" << std::setfill('0') << std::setw(16) << std::hex << mainMemory->loadWord(i) << std::endl;
    }
}

void V9CPU::printStack(std::ostream& out) {
    for (uint64_t i = registerFile[0x1B]->getValue(); i < registerFile[0x1A]->getValue(); i+=8) {
        out << "[0x" << i << "] : 0x" << std::setfill('0') << std::setw(16) << std::hex << mainMemory->loadWord(i) << std::endl;
    }
}