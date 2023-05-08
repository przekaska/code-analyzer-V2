#ifndef _PREPROCESS_CPP
#define _PREPROCESS_CPP

#include <string>

#include "r-expressions.cpp"
#include "symbol-table.cpp"

void preproc(std::string text){
    std::string preproc_instr;
    int position_buff;

    while(search_by_regex(text, PREPROC_REGEX, preproc_instr, position_buff)){
        std::string instr_name = extract_nth_word(preproc_instr, 0);
        std::string first_arg = extract_nth_word(preproc_instr, 1);
        if(instr_name == "#define"){
            symbol_table[first_arg] = make_entry(VAR_CLSS, DEFINED_VAR_T, position_buff, preproc_instr.length()); 
            // TODO: add value
        }
        /* TO FINISH */
        if(instr_name == "#include"){true;}
        if(instr_name == "#ifdef"){true;}
        if(instr_name == "#ifndef"){true;}
        text = text.substr(position_buff + preproc_instr.size());
    }
}




#endif
