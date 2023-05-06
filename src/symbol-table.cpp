#ifndef _SYMBOL_TABLE_CPP
#define _SYMBOL_TABLE_CPP

#include <unordered_map>
#include <string>

#define FUNC_CLSS "FUNC"


struct Entry{
    const char* clss;
    std::string type;
    std::string code;
};

Entry make_entry(const char* clss, std::string type, std::string code = ""){
    Entry entry = {clss, type, code};
    return entry;
}

std::unordered_map<std::string, Entry> symbol_table;



#endif