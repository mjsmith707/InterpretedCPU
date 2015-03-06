//
//  Assembler.cpp
//  Assembler
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#include "Assembler.h"

Assembler::Assembler() {
    // Directive Map
    directiveMap.emplace("ktext", 0xF00F000000000000);
    directiveMap.emplace("kdata", 0xB000000000000000);
    directiveMap.emplace("rodata",0x0100000000000000);
    directiveMap.emplace("data",  0x0020000000000000);
    directiveMap.emplace("text",  0x0000000010010000);
    
    // Opcode Map
    opcodeMap.emplace("add", 0x0);
    opcodeMap.emplace("addi", 0x1);
    opcodeMap.emplace("addu", 0x2);
    opcodeMap.emplace("addiu", 0x3);
    opcodeMap.emplace("sub", 0x4);
    opcodeMap.emplace("subi", 0x5);
    opcodeMap.emplace("subu", 0x6);
    opcodeMap.emplace("subui", 0x7);
    opcodeMap.emplace("mul", 0x8);
    opcodeMap.emplace("muli", 0x9);
    opcodeMap.emplace("mulu", 0xA);
    opcodeMap.emplace("mului", 0xB);
    opcodeMap.emplace("div", 0xC);
    opcodeMap.emplace("divi", 0xD);
    opcodeMap.emplace("divu", 0xE);
    opcodeMap.emplace("diviu", 0xF);
    opcodeMap.emplace("and", 0x10);
    opcodeMap.emplace("or", 0x11);
    opcodeMap.emplace("not", 0x12);
    opcodeMap.emplace("push", 0x13);
    opcodeMap.emplace("pop", 0x14);
    opcodeMap.emplace("mov", 0x15);
    opcodeMap.emplace("call", 0x16);
    opcodeMap.emplace("ret", 0x17);
    opcodeMap.emplace("int", 0x18);
    opcodeMap.emplace("setidt", 0x19);
    opcodeMap.emplace("shl", 0x1A);
    opcodeMap.emplace("shr", 0x1B);
    opcodeMap.emplace("wdt", 0x1C);
    opcodeMap.emplace("setint", 0x1D);
    opcodeMap.emplace("iret", 0x1E);
    
    opcodeMap.emplace("nop", 0x1F);
    opcodeMap.emplace("",0x1F);
    opcodeMap.emplace("jmp", 0x20);
    opcodeMap.emplace("jmpi", 0x21);
    opcodeMap.emplace("je", 0x22);
    opcodeMap.emplace("la", 0x23);
    opcodeMap.emplace("lw", 0x24);
    opcodeMap.emplace("sw", 0x25);
    opcodeMap.emplace("jne", 0x26);
    opcodeMap.emplace("jl", 0x27);
    opcodeMap.emplace("jle", 0x28);
    opcodeMap.emplace("jg", 0x29);
    opcodeMap.emplace("jge", 0x2A);
    opcodeMap.emplace("hlt", 0x3F);
    
    // Register Map
    registerMap.emplace("%g0", 0x0);
    registerMap.emplace("%g1", 0x1);
    registerMap.emplace("%g2", 0x2);
    registerMap.emplace("%g3", 0x3);
    registerMap.emplace("%g4", 0x4);
    registerMap.emplace("%g5", 0x5);
    registerMap.emplace("%g6", 0x6);
    registerMap.emplace("%g7", 0x7);
    registerMap.emplace("%o0", 0x8);
    registerMap.emplace("%o1", 0x9);
    registerMap.emplace("%o2", 0xA);
    registerMap.emplace("%o3", 0xB);
    registerMap.emplace("%o4", 0xC);
    registerMap.emplace("%o5", 0xD);
    registerMap.emplace("%o6", 0xE);
    registerMap.emplace("%o7", 0xF);
    registerMap.emplace("%l0", 0x10);
    registerMap.emplace("%l1", 0x11);
    registerMap.emplace("%l2", 0x12);
    registerMap.emplace("%l3", 0x13);
    registerMap.emplace("%l4", 0x14);
    registerMap.emplace("%l5", 0x15);
    registerMap.emplace("%l6", 0x16);
    registerMap.emplace("%l7", 0x17);
    registerMap.emplace("%i0", 0x18);
    registerMap.emplace("%i1", 0x19);
    registerMap.emplace("%i2", 0x1A);
    registerMap.emplace("%i3", 0x1B);
    registerMap.emplace("%i4", 0x1C);
    registerMap.emplace("%i5", 0x1D);
    registerMap.emplace("%i6", 0x1E);
    registerMap.emplace("%i7", 0x1F);
    registerMap.emplace("%sp", 0x1A);
    registerMap.emplace("%fp", 0x1B);
    registerMap.emplace("%gsp", 0x1C);
    registerMap.emplace("%gfp", 0x1D);
    registerMap.emplace("%ra", 0x1E);
    registerMap.emplace("%tra", 0x1F);
}

bool Assembler::assemble(std::string infile, std::string outfile) {
    std::fstream inFileHandle;
    std::ofstream outFileHandle;
    inFileHandle.open(infile, std::ios_base::in);
    if (inFileHandle.is_open()) {
        outFileHandle.open(outfile, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
        if (outFileHandle.is_open()) {
            std::vector<Assembler::Token> tokens;
            while (!inFileHandle.eof()) {
                std::string line;
                std::getline(inFileHandle, line);
                if (line.empty()) {
                    continue;
                }
                try {
                    tokens.push_back(tokenize(line));
                }
                catch (const std::runtime_error e) {
                    std::cout << "Tokenize Error: " << e.what() << std::endl;
                }
            }
            
            inFileHandle.close();
            
            try {
                std::vector<uint64_t> instructions = convert(tokens);
                uint64_t offset = 0;
                std::cout << "Finalized Instructions" << std::endl;
                std::cout << "Offset    Instruction" << std::endl;
                for (size_t i=0; i<instructions.size(); i++) {
                    std::cout << offset << "    0x" << std::setfill('0') << std::setw(16) << std::hex << instructions[i] << std::endl;
                    outFileHandle.write(reinterpret_cast<const char*>(&instructions[i]), sizeof(int64_t));
                    offset+=8;
                }
                
                outFileHandle.close();
            }
            catch (const std::runtime_error e) {
                std::cout << "Parse Error: " << e.what() << std::endl;
            }
        }
        else {
            inFileHandle.close();
            return false;
        }
    }
    else {
        return false;
    }
    return true;
}


// r format inst %rs, %rt, %rd
// i format inst %rs, %rt, imm
// rt format inst %rs, %rt
// ri format inst %rs, jimm
// j format inst %rs
// ji format inst jimm
// s format inst
// .ktext 0x1234
// .text 0x2345
// .kdata
// .rodata
// .data
Assembler::Token Assembler::tokenize(std::string input) {
    input = trim(input);
    size_t comment = input.find_first_of('#');
    if (comment != std::string::npos) {
        input = input.substr(0, comment);
    }
    std::cout << input << std::endl;
    
    Token token;
    token.type = UNKNOWN;
    token.inst = "";
    token.label = "";
    token.rs = "";
    token.rt = "";
    token.rd = "";
    token.imm = "";
    token.jimm = "";
    
    if (input.empty()) {
        token.type = EMPTY;
        return token;
    }
    
    size_t directivedelimf = input.find_first_of(".");
    if (directivedelimf != std::string::npos) {
        token.type = DIRECTIVE;
        size_t directivedelimb = input.find_first_of(" ");
        if (directivedelimb == std::string::npos) {
            input = input.substr(directivedelimf+1, std::string::npos);
            token.inst = input;
        }
        else {
            token.inst = input.substr(directivedelimf+1, directivedelimb);
            input = input.substr(directivedelimb, std::string::npos);
            token.jimm = input;
        }
        trim(token.inst);
        trim(token.jimm);
        std::cout << "Tokenizer:\nType = '" << token.type << "'\nInst = '" << token.inst << "'\nlabel = '" << token.label <<  "'\nrs = '" << token.rs << "'\nrt = '" << token.rt << "'\nrd = '" << token.rd << "'\nimm = '" << token.imm << "'\njimm = '" << token.jimm << "'" << std::endl;
        return token;
    }
    
    size_t labeldelim = input.find_first_of(':');
    if (labeldelim != std::string::npos) {
        token.label = input.substr(0, labeldelim);
        input = input.substr(labeldelim+1, std::string::npos);
        trim(input);
    }
    
    size_t instdelim = input.find_first_of(' ');
    if (instdelim == std::string::npos) {
        token.type = S_Format;
        token.inst = input;
    }
    else {
        token.inst = input.substr(0, instdelim);
        input = input.substr(instdelim+1, std::string::npos);
        size_t rsdelimf = input.find_first_of('%');
        if (rsdelimf == std::string::npos) {
            token.type = JI_Format;
            token.jimm = input;
        }
        else {
            size_t rsdelimb = input.find_first_of(',');
            if (rsdelimb == std::string::npos) {
                token.type = J_Format;
                token.rs = input;
            }
            else {
                token.rs = input.substr(rsdelimf, rsdelimb);
                input = input.substr(rsdelimb+1, std::string::npos);
                size_t rtdelimf = input.find_first_of('%');
                if (rtdelimf == std::string::npos) {
                    token.type = RI_Format;
                    token.imm = input;
                }
                else {
                    size_t rtdelimb = input.find_first_of(',');
                    if (rtdelimb == std::string::npos) {
                        token.type = RT_Format;
                        token.rt = input;
                    }
                    else {
                        token.rt = input.substr(rtdelimf, rtdelimb-1);
                        input = input.substr(rtdelimb+1, std::string::npos);
                        size_t rddelimf = input.find_first_of('%');
                        if (rddelimf == std::string::npos) {
                            token.type = I_Format;
                            token.imm = input;
                        }
                        else {
                            token.type = R_Format;
                            token.rd = input.substr(rddelimf, std::string::npos);
                        }
                    }
                }
            }
        }
    }
    
    trim(token.inst);
    trim(token.rs);
    trim(token.rt);
    trim(token.rd);
    trim(token.imm);
    trim(token.jimm);
    
    std::cout << "Tokenizer:\nType = '" << token.type << "'\nInst = '" << token.inst << "'\nlabel = '" << token.label <<  "'\nrs = '" << token.rs << "'\nrt = '" << token.rt << "'\nrd = '" << token.rd << "'\nimm = '" << token.imm << "'\njimm = '" << token.jimm << "'" << std::endl;
    
    return token;
}

std::vector<uint64_t> Assembler::convert(std::vector<Token>& tokens) {
    std::vector<uint64_t> instructions;
    std::vector<std::string> intermediateInsts;
    
    // Map Labels
    for (auto &i : tokens) {
        if (i.label.empty()) {
            continue;
        }
        if (std::find(labels.begin(), labels.end(), i.label) == labels.end()) {
            labels.push_back(i.label);
        }
        else {
            throw std::runtime_error("Duplicate labels detected. Label = " + i.label);
        }
    }
    
    // Addresses
    uint64_t baseaddr = 0;
    uint64_t offset = 0x8;
    uint64_t instloc = 0;
    
    for (size_t i=0; i<tokens.size(); i++) {
        if (!tokens.at(i).label.empty()) {
            addresses.emplace(tokens.at(i).label, (uint64_t)(baseaddr + (instloc*offset)));
        }
        instloc++;
    }
    
    instloc = 0;
    
    for (size_t i=0; i<tokens.size(); i++) {
        if (tokens.at(i).type == DIRECTIVE) {
            auto directive = directiveMap.find(tokens.at(i).inst);
            if (directive == directiveMap.end()) {
                throw std::runtime_error("Invalid directive specified: " + tokens.at(i).inst);
            }
            else {
                std::cout << "Directive: " << directive->first << std::endl;
                std::cout << "MapAddr: " << directive->second << std::endl;
                std::cout << "JIMM = " << tokens.at(i).jimm << std::endl;
                if (tokens.at(i).jimm == "") {
                    baseaddr = directive->second;
                }
                else {
                    baseaddr = stoull(tokens.at(i).jimm, nullptr, 16);
                }
            }
        }
        else {
            if (!tokens.at(i).label.empty()) {
                addresses.emplace(tokens.at(i).label, (uint64_t)(baseaddr + (instloc*offset)));
            }
            switch (tokens.at(i).type) {
                case UNKNOWN: {
                    std::string error = "Unknown Token detected. Inst = " + tokens.at(i).inst;
                    throw std::runtime_error(error);
                }
                case EMPTY: {
                    instloc--;
                    break;
                }
                case R_Format: {
                    intermediateInsts.push_back(buildRFormat(tokens.at(i)));
                    break;
                }
                case RI_Format: {
                    intermediateInsts.push_back(buildRIFormat(tokens.at(i)));
                    break;
                }
                case RT_Format: {
                    intermediateInsts.push_back(buildRTFormat(tokens.at(i)));
                    break;
                }
                case I_Format: {
                    intermediateInsts.push_back(buildIFormat(tokens.at(i)));
                    break;
                }
                case J_Format: {
                    intermediateInsts.push_back(buildJFormat(tokens.at(i)));
                    break;
                }
                case JI_Format: {
                    intermediateInsts.push_back(buildJIFormat(tokens.at(i)));
                    break;
                }
                case S_Format: {
                    intermediateInsts.push_back(buildSFormat(tokens.at(i)));
                    break;
                }
                default: {
                    throw std::runtime_error("Unknown Error Occured while building intermediate instructions");
                }
            }
            instloc++;
        }
        
    }
    
    std::cout << "==Finalizing Instructions==" << std::endl;
    // Finalize Instructions
    for (auto &i : intermediateInsts) {
        std::cout << "Instruction = " << i << std::endl;
        try {
            instructions.push_back(stoull(i, nullptr, 2));
        }
        catch (std::out_of_range e) {
            std::cout << "Caught out of range: " << e.what() << std::endl;
        }
    }

    return instructions;
}

unsigned char Assembler::getInstruction(std::string& instruction) {
    auto pos = opcodeMap.find(instruction);
    if (pos == opcodeMap.end()) {
        throw std::runtime_error("Invalid instruction. Inst = " + instruction);
    }
    
    unsigned char inst = pos->second;
    return inst;
}

unsigned char Assembler::getRegister(std::string& Register) {
    auto pos = registerMap.find(Register);
    if (pos == registerMap.end()) {
        throw std::runtime_error("Invalid register. Reg = " + Register);
    }
    
    unsigned char reg = pos->second;
    return reg;
}
// r format inst %rs, %rt, %rd
// i format inst %rs, %rt, imm
// rt format inst %rs, %rt
// ri format inst %rs, rimm
// j format inst %rs
// ji format inst jimm
// s format inst
std::string Assembler::buildRFormat(Token& token) {
    unsigned char inst = getInstruction(token.inst);
    unsigned char rs = getRegister(token.rs);
    unsigned char rt = getRegister(token.rt);
    unsigned char rd = getRegister(token.rd);
    std::string instStr = opcode_dec2bin(inst);
    std::string rsStr = register_dec2bin(rs);
    std::string rtStr = register_dec2bin(rt);
    std::string rdStr = register_dec2bin(rd);
    
    std::string instruction = instStr + rsStr + rtStr + rdStr;
    for (size_t i=instruction.size(); i<64; i++) {
        instruction.push_back('0');
    }
    std::cout << "Rformat = " << instruction << std::endl;
    return instruction;
}

std::string Assembler::buildRIFormat(Token& token) {
    unsigned char inst = getInstruction(token.inst);
    unsigned char rs = getRegister(token.rs);
    unsigned char zero = 0x0;
    
    std::string instStr = opcode_dec2bin(inst);
    std::string rsStr = register_dec2bin(rs);
    std::string zeroStr = register_dec2bin(zero);
    std::string immStr = imm_getStr(token.imm);
    std::string instruction = instStr + rsStr + zeroStr + immStr;
    std::cout << "RIformat = " << instruction << std::endl;
    return instruction;
}

std::string Assembler::buildRTFormat(Token& token) {
    unsigned char inst = getInstruction(token.inst);
    unsigned char rs = getRegister(token.rs);
    unsigned char rt = getRegister(token.rt);
    std::string instStr = opcode_dec2bin(inst);
    std::string rsStr = register_dec2bin(rs);
    std::string rtStr = register_dec2bin(rt);
    
    std::string instruction = instStr + rsStr + rtStr;
    for (size_t i=instruction.size(); i<64; i++) {
        instruction.push_back('0');
    }
    std::cout << "RTformat = " << instruction << std::endl;
    return instruction;
}

std::string Assembler::buildIFormat(Token& token) {
    unsigned char inst = getInstruction(token.inst);
    unsigned char rs = getRegister(token.rs);
    unsigned char rt = getRegister(token.rt);
    std::string instStr = opcode_dec2bin(inst);
    std::string rsStr = register_dec2bin(rs);
    std::string rtStr = register_dec2bin(rt);
    std::string immStr = imm_getStr(token.imm);
    
    std::string instruction = instStr + rsStr + rtStr + immStr;
    std::cout << "Iformat = " << instruction << std::endl;
    return instruction;
}

std::string Assembler::buildJFormat(Token& token) {
    unsigned char inst = getInstruction(token.inst);
    unsigned char rs = getRegister(token.rs);
    std::string instStr = opcode_dec2bin(inst);
    std::string rsStr = register_dec2bin(rs);
    
    std::string instruction = instStr + rsStr;
    for (size_t i=instruction.size(); i<64; i++) {
        instruction.push_back('0');
    }
    std::cout << "Jformat = " << instruction << std::endl;
    return instruction;
}

std::string Assembler::buildJIFormat(Token& token) {
    unsigned char inst = getInstruction(token.inst);
    std::string instStr = opcode_dec2bin(inst);
    std::string jimmStr = jimm_getStr(token.jimm);
    std::string instruction = instStr + jimmStr;
    std::cout << "JIformat = " << instruction << std::endl;
    return instruction;
}

std::string Assembler::buildSFormat(Token& token) {
    unsigned char inst = getInstruction(token.inst);
    std::string instStr = opcode_dec2bin(inst);
    std::string instruction = instStr;
    for (size_t i=instruction.size(); i<64; i++) {
        instruction.push_back('0');
    }
    std::cout << "Sformat = " << instruction << std::endl;
    return instruction;
}

// http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
inline std::string& Assembler::ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
inline std::string& Assembler::rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
inline std::string& Assembler::trim(std::string &s) {
    return ltrim(rtrim(s));
}

// http://www.cplusplus.com/forum/general/10898/
std::string Assembler::opcode_dec2bin(unsigned char n) {
    const int size=6;
    std::string res;
    for (int i=size-1; i>=0; i--) {
        bool bit = ((n >> i) & 1);
        if (bit) {
            res.push_back('1');
        }
        else {
            res.push_back('0');
        }
    }
    return res;
}

std::string Assembler::register_dec2bin(unsigned char n) {
    const int size=5;
    std::string res;
    for (int i=size-1; i>=0; i--) {
        bool bit = ((n >> i) & 1);
        if (bit) {
            res.push_back('1');
        }
        else {
            res.push_back('0');
        }
    }
    return res;
}

std::string Assembler::int64t_dec2bin(uint64_t n) {
    const int size=sizeof(n)*8;
    std::string res;
    for (int i=size-1; i>=0; i--) {
        bool bit = ((n >> i) & 1);
        if (bit) {
            res.push_back('1');
        }
        else {
            res.push_back('0');
        }
    }
    return res;
}

std::string Assembler::imm_dec2bin(uint64_t n) {
    const int size=sizeof(n)*8;
    std::string res;
    for (int i=size-1; i>=0; i--) {
        bool bit = ((n >> i) & 1);
        if (bit) {
            res.push_back('1');
        }
        else {
            res.push_back('0');
        }
    }
    return res;
}

std::string Assembler::imm_getStr(std::string imm) {
    auto loc = addresses.find(imm);
    std::string res;
    if (loc == addresses.end()) {
        size_t pos = imm.find("0x");
        if (pos != std::string::npos) {
            res = hexstr_to_binstr(imm);
        }
        else {
            res = decstr_to_binstr(imm);
        }
    }
    else {
        int64_t address = loc->second;
        res = int64t_dec2bin(address);
    }
    res.erase(0,16);
    return res;
}

std::string Assembler::jimm_getStr(std::string imm) {
    auto loc = addresses.find(imm);
    std::string res;
    if (loc == addresses.end()) {
        size_t pos = imm.find("0x");
        if (pos != std::string::npos) {
            res = hexstr_to_binstr(imm);
        }
        else {
            res = decstr_to_binstr(imm);
        }
    }
    else {
        int64_t address = loc->second;
        res = int64t_dec2bin(address);
    }
    res.erase(0,6);
    return res;
}

std::string Assembler::decstr_to_binstr(std::string& str) {
    int64_t integral = stoll(str);
    std::string res = int64t_dec2bin(integral);
    return res;
}

std::string Assembler::hexstr_to_binstr(std::string& str) {
    int64_t integral = stoll(str, nullptr, 16);
    std::string res = int64t_dec2bin(integral);
    return res;
}







