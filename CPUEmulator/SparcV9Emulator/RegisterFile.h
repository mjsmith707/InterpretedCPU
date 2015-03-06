//
//  RegisterFile.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/18/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef CPUEmulator_RegisterFile_h
#define CPUEmulator_RegisterFile_h

#include <map>
#include "Register.h"

typedef std::map<unsigned char, Register*> RegisterFile;

#endif
