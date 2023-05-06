#ifndef _R_EXPRESSIONS_CPP
#define _R_EXPRESSIONS_CPP

#define FUNC_DECOR_REGEX "(void|int|float)+(\\*)?\\s+(\\*)?\\w+(\\s+)?\\(((\\s?(void|int|float)+(\\*)?\\s+(\\*)?\\w+(\\s+)?,?\\s?)?)+\\)"
#define DECOR_TYPE_REGEX "(void|int|float)"
#define DECOR_NAME_REGEX "\\w+\\s?(?=\\()"

#include <string>
#include <regex>


std::string find_in(std::string text, std::string expression){
    std::smatch match;
    std::regex expr(expression);

    regex_search(text, match, expr);
    return match[0];
}

#endif
