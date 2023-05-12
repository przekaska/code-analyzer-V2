#ifndef _R_EXPRESSIONS_CPP
#define _R_EXPRESSIONS_CPP

#define DECOR_FUNC_REGEX "(void|int|float)\\s+\\w+\\((\\w|\\W)*?(?=\\{)"
#define TYPE_DECOR_REGEX "(void|int|float)"
#define NAME_DECOR_REGEX "\\w+\\s*(?=\\()"
#define PREPROC_REGEX "#.+"
#define WORD_PREPROC_REGEX "#\\s*\\w+"
#define PSEUDO_FUNC_REGEX "(if|for|while|do)"

#define SCOPE_FINDING_REGEX "\\b(if|for|while|do)\\s*\\(|(void|int|float)\\s+\\w+\\((\\w|\\W)*?(?=\\{)"

#include <string>
#include <cctype>
#include <regex>

std::string extract_by_regex(std::string text, std::string expression){
    std::smatch match;
    std::regex expr(expression);

    regex_search(text, match, expr);
    return match[0];
}

bool search_by_regex(std::string text, std::string regex,
    std::string &result_buffer, int &position){
    std::smatch match;
    std::regex func_decor_expr(regex);
    bool result = regex_search(text, match, func_decor_expr);
    result_buffer = match[0];
    position = match.position();
    return result;
}

std::string extract_nth_word(std::string text, int n, int start = 0){
    int length = 0;
    while(text[start] != '\0'){
        if(not n) break;
        n -= (std::isspace(text[start]) and not std::isspace(text[start + 1])); 
        start++;
    }
    while(not std::isspace(text[start + length]))
        length++;
    return text.substr(start, length);
}


#endif
