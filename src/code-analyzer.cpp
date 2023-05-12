#ifndef _CODE_ANALYZER_CPP
#define _CODE_ANALYZER_CPP

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <regex>    // Probably going to change to re2 library
#include <vector>

#include "simple-tree.cpp"
#include "functions.cpp"
#include "symbol-table.cpp"
#include "preprocess.cpp"
#include "scopes.cpp"

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
    // preproc(text);  
    // find_funcs(text);
    find_scopes(text);

    // for(int num : sth){
    //     for(int i = num; i < num + 20; i++){
    //         std::cout << text[i];
    //     }
    //     std::cout << std::endl << "DUPA" << std::endl;
    // }

    // std::cout << symbol_table["jump"].clss << std::endl;
    // std::cout << symbol_table["jump"].type << std::endl;
    // std::cout << symbol_table["jump"].code << std::endl;
    // for(int i = 0; i < 20; i++)
    //     std::cout << text[symbol_table["jump"].end - 20 + i];
    // for(int i = 1; i < 2; i++)
    for(auto sth : symbol_table){
        std::cout << sth.first << " : " << sth.second.clss << " " << sth.second.type << std::endl;
        std::cout << sth.second.code << std::endl; 
    }
}

#endif
