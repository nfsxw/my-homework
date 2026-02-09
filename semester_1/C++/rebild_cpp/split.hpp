#ifndef SPLIT_HPP
#define SPLIT_HPP

#include <string>

inline int Count_tokens(std::string& text, std::string& septs){
    int tokens_counter{};
    bool in_token{};
    for (char c : text){
        bool is_sep{};
        for (char sep : septs){
            if(c == sep){
                is_sep = 1;
                break;
            }
        }
        if(is_sep && in_token){
            ++tokens_counter;
            in_token = 0;          
        }
        if(!is_sep) in_token = 1;
    }
    if(in_token){
        ++tokens_counter;
    }
    return tokens_counter;
}

#endif 