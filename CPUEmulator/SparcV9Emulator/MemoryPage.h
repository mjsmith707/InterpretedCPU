//
//  MemoryPage.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__MemoryPage__
#define __CPUEmulator__MemoryPage__

#include <vector>

class MemoryPage {
private:
    uint64_t virtualAddress;
    std::vector<unsigned char> page;
    size_t getPosition(uint64_t);
public:
    MemoryPage(uint64_t, size_t);
    uint64_t getAddress();
    void storeByte(uint64_t, unsigned char);
    unsigned char loadByte(uint64_t);
};

#endif /* defined(__CPUEmulator__MemoryPage__) */
