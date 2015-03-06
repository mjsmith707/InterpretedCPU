//
//  Interrupt.cpp
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Interrupt.h"

Interrupt::Interrupt(short t) : std::exception(), type(t) {
};

short Interrupt::getType() {
    return type;
}