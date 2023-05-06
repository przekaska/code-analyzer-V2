#ifndef _FUNCTIONS_CPP
#define _FUNCTIONS_CPP

#include <string>
#include <regex>
#include <vector>

#include "symbol-table.cpp"
#include "simple-tree.cpp"
#include "r-expressions.cpp"

int find_func_end(std::string &text){
    int curly_level = 0;
    for(char &ch : text){
        curly_level += (ch == '{') - (ch == '}');
        if(not curly_level)
            return &ch - &text[0];
    }
    return -1;
}

void find_funcs(std::string text){ 
    std::string func_decor;
    int position;
    int start = 0;
    std::string name;
    std::string type;
    int stop;
    while (search_by_regex(text, DECOR_FUNC_REGEX, func_decor, position)){ // TODO: split it into functions
        start += position;
        name = extract_by_regex(func_decor, NAME_DECOR_REGEX);
        type = extract_by_regex(func_decor, TYPE_DECOR_REGEX);
        stop = find_func_end(text) + start + func_decor.size();
        symbol_table[name] = make_entry(FUNC_CLSS, type, start, stop);
        
        text = text.substr(position + func_decor.size());
        symbol_table[name].code = text.substr(1, find_func_end(text) - 2);
        start += func_decor.size();
    }
}

#endif