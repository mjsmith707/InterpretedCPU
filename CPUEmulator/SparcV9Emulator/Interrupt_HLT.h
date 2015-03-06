//
//  Interrupt_HLT.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Interrupt_HLT__
#define __CPUEmulator__Interrupt_HLT__

#include "Interrupt.h"

class Interrupt_HLT : public Interrupt {
public:
    Interrupt_HLT();
    ~Interrupt_HLT();
};

#endif /* defined(__CPUEmulator__Interrupt_HLT__) */
