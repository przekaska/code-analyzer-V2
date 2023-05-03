#ifndef _CODE_ANALYZER_CPP
#define _CODE_ANALYZER_CPP

#include <iostream>
#include <fstream>

#include "simpletree.cpp"


void readfile(const char *filename, std::string &text_buffer){
    std::ifstream source_file(filename);
    std::string line;
    if (source_file.is_open()){
        while (getline(source_file, line)){
            text_buffer += line + '\n';
        }
        source_file.close();
    }
}


int main(){
    std::string text;
    readfile("test_files/testfile1.c", text);
    
    std::cout << text << std::endl;
}

#endif
