//
//  main.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/13/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include <iostream>
#include <thread>
#include "V9CPU.h"
#include "Register.h"
#include "Instruction_ADD.h"
#include "InstructionContext.h"
#include <cstdint>
#include "Memory.h"

//  27 jl   18    19        0000 this is a problem
//  100111 11000 11001 000000000000000000000000000000000000000000000000
//  100111 11000 11001 000000000000000000010000000000010000000011110000
//  011111 00000 00000 000000000000000000000000000000000000000000000000


int main(int argc, const char * argv[]) {
    V9CPU cpu0;

    std::string kernel = "/Users/msmith/Desktop/Interpreted CPU/asm code/kernelout.bin";
    std::string watchdog = "/Users/msmith/Desktop/Interpreted CPU/asm code/trap_watchdog.bin";
    std::string doublefault = "/Users/msmith/Desktop/Interpreted CPU/asm code/trap_doublefault.bin";
    std::string alignment = "/Users/msmith/Desktop/Interpreted CPU/asm code/trap_alignment.bin";
    std::string div0 = "/Users/msmith/Desktop/Interpreted CPU/asm code/trap_div0.bin";
    std::string test = "/Users/msmith/Desktop/Interpreted CPU/asm code/testout.bin";
    std::string f = "/Users/msmith/Desktop/Interpreted CPU/asm code/fout.bin";
    std::ofstream output;
    output.open("/Users/msmith/Desktop/output.txt", std::ios_base::out | std::ios_base::trunc);
    cpu0.loadText(0xF00F000000000000, watchdog);
    cpu0.loadText(0xF01F000000000000, doublefault);
    cpu0.loadText(0xF02F000000000000, alignment);
    cpu0.loadText(0xF03F000000000000, div0);
    cpu0.loadText(0x0000000010010000, kernel);
    cpu0.loadText(0x0000A00000000000, test);
    cpu0.loadText(0x0000B00000000000, f);
    
    std::thread CPU0(std::bind(&V9CPU::start, &cpu0));
    std::this_thread::sleep_for(std::chrono::seconds(10));
    
    cpu0.sendInterrupt(Interrupt_HLT());
    CPU0.join();
    
    std::cout << "===Global Stack===" << std::endl;
    cpu0.printKStack(std::cout);
    std::cout << std::endl << "===User Stack===" << std::endl;
    cpu0.printStack(std::cout);
    std::cout << std::endl << "===Register File===" << std::endl;
    cpu0.printRegisterFile(std::cout);
    
    output.flush();
    output.close();
    return 0;
}

