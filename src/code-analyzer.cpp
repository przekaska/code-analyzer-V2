#ifndef _CODE_ANALYZER_CPP
#define _CODE_ANALYZER_CPP

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <regex>
#include <vector>

#include "simple-tree.cpp"
#include "functions.cpp"


void readfile(const char *filename, std::string &text_buffer){
    std::ifstream source_file(filename);
    std::string line;
    if (source_file.is_open()){         // TODO: reading only a chunk of code
        while (getline(source_file, line))
            text_buffer += line + '\n';
        source_file.close();
    }
}

int main(){
    std::string text; 
    readfile("test_files/testfile1.c", text);
}

#endif
