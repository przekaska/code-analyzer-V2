#ifndef _SYMBOL_TABLE_CPP
#define _SYMBOL_TABLE_CPP

#include <unordered_map>
#include <string>

#define FUNC_CLSS "FUNC"
#define VAR_CLSS "VARB"

#define DEFINED_VAR_T "DEF_VAR"


struct Entry{
    const char* clss;
    std::string type;
    int start;
    int end;
    std::string code;
};

Entry make_entry(const char* clss, std::string type, int start, int end=-1, std::string code = ""){
    Entry entry = {clss, type, start, end, code};
    return entry;
}

std::unordered_map<std::string, Entry> symbol_table;



#endif