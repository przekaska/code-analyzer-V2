#ifndef _SYMBOL_TABLE_CPP
#define _SYMBOL_TABLE_CPP

#include <unordered_map>
#include <string>

#define FUNC_CLSS "FUNC"


struct Entry{
    const char* clss;
    std::string type;
    std::string code;

    Entry(const char* new_cls, std::string new_type){
        clss = new_cls;
        type = new_type;
    }
};


std::unordered_map<std::string, Entry*> symbol_table;

#endif