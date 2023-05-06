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
    std::smatch match;
    std::regex func_decor_expr(FUNC_DECOR_REGEX);

    while (regex_search(text, match, func_decor_expr)){
        std::string name = extract_from(match[0], DECOR_NAME_REGEX);
        std::string type = extract_from(match[0], DECOR_TYPE_REGEX);
        static Entry entry("func", type);
        symbol_table[name] = &entry;
        text = text.substr(match.position() + match.length());
        symbol_table[name]->code = text.substr(1, find_func_end(text) - 2);
    }
}

#endif