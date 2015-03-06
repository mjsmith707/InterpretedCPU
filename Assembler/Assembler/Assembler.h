//
//  Assembler.h
//  Assembler
//
//  Created by Matt Smith on 11/14/14.
//  Copyright (c) 2014 Matt Smith. All rights reserved.
//

#ifndef __Assembler__Assembler__
#define __Assembler__Assembler__

#include <string>
#include <fstream>
#include <unordered_map>
#include <cstdint>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

class Assembler {
public:
    Assembler();
    bool assemble(std::string, std::string);
private:
    std::unordered_map<std::string, unsigned char> opcodeMap;
    std::unordered_map<std::string, unsigned char> registerMap;
    std::unordered_map<std::string, uint64_t> directiveMap;
    std::unordered_map<std::string, uint64_t> addresses;
    std::vector<std::string> labels;
    
    enum InstFormat {
        UNKNOWN, DIRECTIVE, EMPTY, R_Format, RI_Format, RT_Format, I_Format, J_Format, JI_Format, S_Format
    };
    
    struct Token {
        InstFormat type;
        std::string inst;
        std::string label;
        std::string rs;
        std::string rt;
        std::string rd;
        std::string imm;
        std::string rimm;
        std::string jimm;
    };
    
    Token tokenize(std::string);
    std::vector<uint64_t> convert(std::vector<Token>&);
    unsigned char getInstruction(std::string&);
    unsigned char getRegister(std::string&);
    std::string buildRFormat(Token&);
    std::string buildRIFormat(Token&);
    std::string buildRTFormat(Token&);
    std::string buildIFormat(Token&);
    std::string buildJFormat(Token&);
    std::string buildJIFormat(Token&);
    std::string buildSFormat(Token&);
    
    static inline std::string& ltrim(std::string &s);
    static inline std::string& rtrim(std::string &s);
    static inline std::string& trim(std::string &s);
    std::string opcode_dec2bin(unsigned char);
    std::string register_dec2bin(unsigned char);
    std::string int64t_dec2bin(uint64_t);
    std::string imm_dec2bin(uint64_t);
    std::string imm_getStr(std::string);
    std::string jimm_getStr(std::string);
    std::string decstr_to_binstr(std::string& str);
    std::string hexstr_to_binstr(std::string& str);
};

#endif /* defined(__Assembler__Assembler__) */
