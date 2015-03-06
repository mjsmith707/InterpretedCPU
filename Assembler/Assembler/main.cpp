//
//  main.cpp
//  Assembler
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include <iostream>
#include "Assembler.h"

int main(int argc, const char * argv[]) {
    Assembler* assembler = new Assembler();
    std::string kernel = "/Users/msmith/Desktop/Interpreted CPU/asm code/kernel.asm";
    std::string kernelout = "/Users/msmith/Desktop/Interpreted CPU/asm code/kernelout.bin";
    std::string watchdog = "/Users/msmith/Desktop/Interpreted CPU/asm code/trap_watchdog.asm";
    std::string watchdogout = "/Users/msmith/Desktop/Interpreted CPU/asm code/trap_watchdog.bin";
    std::string doublefault = "/Users/msmith/Desktop/Interpreted CPU/asm code/trap_doublefault.asm";
    std::string doublefaultout = "/Users/msmith/Desktop/Interpreted CPU/asm code/trap_doublefault.bin";
    std::string align = "/Users/msmith/Desktop/Interpreted CPU/asm code/trap_alignment.asm";
    std::string alignout = "/Users/msmith/Desktop/Interpreted CPU/asm code/trap_alignment.bin";
    std::string div0 = "/Users/msmith/Desktop/Interpreted CPU/asm code/trap_div0.asm";
    std::string div0out = "/Users/msmith/Desktop/Interpreted CPU/asm code/trap_div0.bin";
    std::string test = "/Users/msmith/Desktop/Interpreted CPU/asm code/test.asm";
    std::string testout = "/Users/msmith/Desktop/Interpreted CPU/asm code/testout.bin";
    std::string f = "/Users/msmith/Desktop/Interpreted CPU/asm code/f.asm";
    std::string fout = "/Users/msmith/Desktop/Interpreted CPU/asm code/fout.bin";
    
    //assembler->assemble(kernel, kernelout);
    //assembler->assemble(watchdog, watchdogout);
    //assembler->assemble(doublefault, doublefaultout);
    //assembler->assemble(align, alignout);
    //assembler->assemble(div0, div0out);
    //assembler->assemble(test, testout);
    assembler->assemble(f, fout);

    return 0;
}
