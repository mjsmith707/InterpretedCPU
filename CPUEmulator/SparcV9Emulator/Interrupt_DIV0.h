//
//  Interrupt_DIV0.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/16/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Interrupt_DIV0__
#define __CPUEmulator__Interrupt_DIV0__

#include "Interrupt.h"

class Interrupt_DIV0 : public Interrupt {
public:
    Interrupt_DIV0();
    ~Interrupt_DIV0();
};

#endif /* defined(__CPUEmulator__Interrupt_DIV0__) */
