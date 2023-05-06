#ifndef _PREPROCESS_CPP
#define _PREPROCESS_CPP

#include <string>

#include "r-expressions.cpp"

void preproc(std::string text){
    std::smatch match;
    std::regex expr(PREPROC_REGEX);

    while(regex_search(text, match, expr)){
        
        text = text.substr(match.position() + match.length());
    }
}




#endif
