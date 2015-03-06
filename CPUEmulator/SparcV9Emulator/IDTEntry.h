//
//  IDTEntry.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef CPUEmulator_IDTEntry_h
#define CPUEmulator_IDTEntry_h

struct IDTEntry {
    bool active;
    int64_t address;
};

#endif
