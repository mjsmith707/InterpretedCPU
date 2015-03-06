//
//  Interrupt_Timer.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Interrupt_Timer__
#define __CPUEmulator__Interrupt_Timer__

#include "Interrupt.h"

class Interrupt_Timer : public Interrupt {
public:
    Interrupt_Timer();
    ~Interrupt_Timer();
};

#endif /* defined(__CPUEmulator__Interrupt_Timer__) */
