//
//  IDTTable.h
//  CPUEmulator
//
//  Created by Matt Smith on 11/18/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef CPUEmulator_IDTTable_h
#define CPUEmulator_IDTTable_h

#include <map>
#include "IDTEntry.h"

typedef std::map<short, IDTEntry*> IDTTable;

#endif
