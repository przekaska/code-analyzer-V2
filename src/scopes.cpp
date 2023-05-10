#ifndef _SCOPES_CPP
#define _SCOPES_CPP

#include <string>

#include "r-expressions.cpp"
#include <iostream>

// start from scopes
void find_scopes(std::string text){
    std::string scope_declar;
    int position;
    while (search_by_regex(text, SCOPE_FINDING_REGEX, scope_declar, position)){
        int cur_brack_lvl = 0;
        int brack_lvl = 0;
        int i = position;
        while(text[i]){
            if(text[i] == ';' and not brack_lvl and not cur_brack_lvl)
                break;
            else if(text[i] == '}' and not brack_lvl and cur_brack_lvl == 1)
                break;
            cur_brack_lvl += (text[i] == '{') - (text[i] == '}');
            brack_lvl += (text[i] == '(') - (text[i] == ')');
            i++;
        }
        text = text.substr(position + scope_declar.size());
    }
}



#endif