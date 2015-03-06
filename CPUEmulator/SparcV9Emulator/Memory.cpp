//
//  Memory.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/13/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Memory.h"

Memory::Memory(size_t bytes) : pageSize(bytes) {

}

MemoryPage* Memory::getPage(uint64_t address) {
    uint64_t pageAddr = (address >> 3);
    try {
        auto pageloc = pageTable.find(pageAddr);
        if (pageloc == pageTable.end()) {
            MemoryPage* page = new MemoryPage(pageAddr, pageSize);
            pageTable.emplace(pageAddr, page);
            return page;
        }
        else {
            return pageloc->second;
        }
    }
    catch (const std::exception) {
        MemoryPage* page = new MemoryPage(pageAddr, pageSize);
        pageTable.emplace(pageAddr, page);
        return page;
    }
}

void Memory::storeWord(uint64_t address, uint64_t word) {
    if ((address % 8) != 0) {
        throw Interrupt_ALIGNMENT();
    }
    MemoryPage* page0 = getPage(address);
    MemoryPage* page1 = getPage(address+1);
    MemoryPage* page2 = getPage(address+2);
    MemoryPage* page3 = getPage(address+3);
    MemoryPage* page4 = getPage(address+4);
    MemoryPage* page5 = getPage(address+5);
    MemoryPage* page6 = getPage(address+6);
    MemoryPage* page7 = getPage(address+7);
    page0->storeByte(address, word >> 56);
    page1->storeByte(address+1, word >> 48);
    page2->storeByte(address+2, word >> 40);
    page3->storeByte(address+3, word >> 32);
    page4->storeByte(address+4, word >> 24);
    page5->storeByte(address+5, word >> 16);
    page6->storeByte(address+6, word >> 8);
    page7->storeByte(address+7, word);
}

void Memory::storeByte(uint64_t address, unsigned char value) {
    if ((address % 2) != 0) {
        throw Interrupt_ALIGNMENT();
    }
    MemoryPage* page0 = getPage(address);
    page0->storeByte(address, value);
}

int64_t Memory::loadWord(uint64_t address) {
    if ((address % 8) != 0) {
        throw Interrupt_ALIGNMENT();
    }
    MemoryPage* page0 = getPage(address);
    MemoryPage* page1 = getPage(address+1);
    MemoryPage* page2 = getPage(address+2);
    MemoryPage* page3 = getPage(address+3);
    MemoryPage* page4 = getPage(address+4);
    MemoryPage* page5 = getPage(address+5);
    MemoryPage* page6 = getPage(address+6);
    MemoryPage* page7 = getPage(address+7);
    int64_t value;
    value = page0->loadByte(address);
    value <<= 8;
    value |= page1->loadByte(address+1);
    value <<= 8;
    value |= page2->loadByte(address+2);
    value <<= 8;
    value |= page3->loadByte(address+3);
    value <<= 8;
    value |= page4->loadByte(address+4);
    value <<= 8;
    value |= page5->loadByte(address+5);
    value <<= 8;
    value |= page6->loadByte(address+6);
    value <<= 8;
    value |= page7->loadByte(address+7);
    return value;
}

unsigned char Memory::loadByte(uint64_t address) {
    if ((address % 2) != 0) {
        throw Interrupt_ALIGNMENT();
    }
    MemoryPage* page0 = getPage(address);
    unsigned char value = page0->loadByte(address);
    return value;
}