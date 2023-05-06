#ifndef _R_EXPRESSIONS_CPP
#define _R_EXPRESSIONS_CPP

#define DECOR_FUNC_REGEX "(void|int|float)+(\\*)?\\s+(\\*)?\\w+(\\s+)?\\(((\\s?(void|int|float)+(\\*)?\\s+(\\*)?\\w+(\\s+)?,?\\s?)?)+\\)"
#define TYPE_DECOR_REGEX "(void|int|float)"
#define NAME_DECOR_REGEX "\\w+\\s?(?=\\()"
#define PREPROC_REGEX "#.+"
#define DEFINE_PREPROC_REGEX "#define.+"

#include <string>
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


#endif
