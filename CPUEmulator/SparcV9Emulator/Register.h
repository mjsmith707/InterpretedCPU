//
//  Register.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/13/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __CPUEmulator__Register__
#define __CPUEmulator__Register__

#include <cstdint>

class Register {
private:
        bool muted;
        uint64_t value;
public:
        Register();
        Register(uint64_t);
        Register(bool);
    
        uint64_t getValue();
        void setValue(uint64_t);
};

#endif /* defined(__CPUEmulator__Register__) */
