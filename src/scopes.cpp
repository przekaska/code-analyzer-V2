#ifndef _SCOPES_CPP
#define _SCOPES_CPP

#include <string>
#include <iostream>
#include <vector>

#include "r-expressions.cpp"
#include "symbol-table.cpp"


std::vector<int> sth;
void find_scopes(std::string text){
    std::string scope_declar;
    int start;
    int removed_chars = 0;
    /* this code looks awful but works, going to change it*/
    while (search_by_regex(text, SCOPE_FINDING_REGEX, scope_declar, start)){
        int cur_brack_lvl = 0;
        int parenthesis_level = 0;
        int stop = start;
        while(text[stop]){
            if(text[stop] == ';' and not parenthesis_level and not cur_brack_lvl)
                break;
            else if(text[stop] == '}' and not parenthesis_level and cur_brack_lvl == 1)
                break;
            cur_brack_lvl += (text[stop] == '{') - (text[stop] == '}');
            parenthesis_level += (text[stop] == '(') - (text[stop] == ')');
            stop++;
        }
        symbol_table[std::to_string(start + removed_chars)] = make_entry(SCOPE_CLSS, "", start + removed_chars, stop + removed_chars);
        text = text.substr(start + scope_declar.size());
        removed_chars += scope_declar.size() + start;
    }
}



#endif
