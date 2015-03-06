//
//  Interrupt.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Interrupt__
#define __CPUEmulator__Interrupt__

#include <stdexcept>

class Interrupt : public std::exception {
private:
    short type;
public:
    Interrupt(short);
    virtual ~Interrupt() throw() {};
    short getType();
};

#endif /* defined(__CPUEmulator__Interrupt__) */
