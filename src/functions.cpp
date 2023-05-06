#ifndef _FUNCTIONS_CPP
#define _FUNCTIONS_CPP

#include <string>
#include <regex>
#include <vector>

#include "simple-tree.cpp"
#include "r-expressions.cpp"

class Func{
    public:
    std::string name;
    std::string type;
    std::string code;

    Func(std::string new_name, std::string new_type){
        name = new_name;
        type = new_type;
    }
};

std::vector <Func> funcs; // temp solution

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
        funcs.push_back( Func(find_in(match[0], DECOR_NAME_REGEX), find_in(match[0], DECOR_TYPE_REGEX)) );
        text = text.substr(match.position() + match.length());
        funcs.back().code = text.substr(1, find_func_end(text) - 2);
    }
}

#endif