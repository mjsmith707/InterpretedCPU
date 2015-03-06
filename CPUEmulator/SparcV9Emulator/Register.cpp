//
//  Register.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/13/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Register.h"

Register::Register(uint64_t val) : muted(false), value(val) {
}

Register::Register() : muted(false), value(0) {
}

Register::Register(bool mute) : muted(mute), value(0) {
}

uint64_t Register::getValue() {
    return value;
}

void Register::setValue(uint64_t newval) {
    if (!muted) {
        value = newval;
    }
}