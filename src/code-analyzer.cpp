#ifndef _CODE_ANALYZER_CPP
#define _CODE_ANALYZER_CPP

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <regex>
#include <vector>

#include "simple-tree.cpp"
#include "scopes.cpp"


#define FUNC_DECOR_REGEX "(void|int|float)+(\\*)?\\s+(\\*)?\\w+(\\s+)?\\(((\\s?(void|int|float)+(\\*)?\\s+(\\*)?\\w+(\\s+)?,?\\s?)?)+\\)"
#define DECOR_TYPE_REGEX "(void|int|float)"
#define DECOR_NAME_REGEX "\\w+\\s?(?=\\()"


void readfile(const char *filename, std::string &text_buffer){
    std::ifstream source_file(filename);
    std::string line;
    if (source_file.is_open()){         // TODO: reading only a chunk of code
        while (getline(source_file, line))
            text_buffer += line + '\n';
        source_file.close();
    }
}

std::string find_in(std::string text, std::string expression){
    std::smatch match;
    std::regex expr(expression);

    regex_search(text, match, expr);
    return match[0];
}

int main(){
    std::string text; 
    readfile("test_files/testfile1.c", text);
}

#endif
