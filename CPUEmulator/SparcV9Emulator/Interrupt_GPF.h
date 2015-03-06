//
//  Interrupt_GPF.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/17/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Interrupt_GPF__
#define __CPUEmulator__Interrupt_GPF__

#include "Interrupt.h"

class Interrupt_GPF : public Interrupt {
public:
    Interrupt_GPF();
    ~Interrupt_GPF();
};

#endif /* defined(__CPUEmulator__Interrupt_GPF__) */
