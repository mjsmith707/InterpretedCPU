//
//  MemoryPage.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/15/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "MemoryPage.h"

MemoryPage::MemoryPage(uint64_t baseaddr, size_t pagesize) : virtualAddress(baseaddr) {
    page.resize(pagesize);
}

uint64_t MemoryPage::getAddress() {
    return virtualAddress;
}

size_t MemoryPage::getPosition(uint64_t address) {
    size_t position = (address & 0x7);
    return position;
}

void MemoryPage::storeByte(uint64_t address, unsigned char byte) {
    page.at(getPosition(address)) = byte;
}

unsigned char MemoryPage::loadByte(uint64_t address) {
    return page.at(getPosition(address));
}