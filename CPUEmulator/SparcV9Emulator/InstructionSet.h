//
//  InstructionSet.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/18/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef CPUEmulator_InstructionSet_h
#define CPUEmulator_InstructionSet_h
#include "Instruction.h"
#include <unordered_map>

typedef std::map<unsigned char, Instruction*> InstructionSet;
//typedef std::vector<Instruction*> InstructionSet;
//typedef std::unordered_map<unsigned char, Instruction*> InstructionSet;
#endif
