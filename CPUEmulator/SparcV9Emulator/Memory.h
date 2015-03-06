//
//  Memory.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/13/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Memory__
#define __CPUEmulator__Memory__

#include <vector>
#include <map>
#include <cstdint>
#include <algorithm>
#include "MemoryPage.h"
#include "Interrupt_ALIGNMENT.h"

class Memory {
private:
    size_t pageSize;
    std::map<uint64_t, MemoryPage*> pageTable;
    MemoryPage* getPage(uint64_t);
    
public:
    Memory(size_t);
    void storeWord(uint64_t, uint64_t);
    void storeByte(uint64_t, unsigned char);
    int64_t loadWord(uint64_t);
    unsigned char loadByte(uint64_t);
};
#endif /* defined(__CPUEmulator__Memory__) */
