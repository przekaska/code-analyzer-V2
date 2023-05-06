#ifndef _FUNCTIONS_CPP
#define _FUNCTIONS_CPP

#include <string>

#include "simple-tree.cpp"

class Func{
    public:
    std::string name;
    std::string type;
    std::string code;

    Func(std::string new_name, std::string new_type){
        name = new_name;
        type = new_type;
    }
};


#endif