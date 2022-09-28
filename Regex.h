//
// Created by xande on 9/2/2022.
//

#ifndef UNTITLED8_REGEX_H
#define UNTITLED8_REGEX_H
#include <string>
#include <cassert>
class Regex {
    std::string pattern, current_string;
public:
    Regex() {
        pattern = "";
        current_string = "";
    }
    std::string search(std::string pattern, std::string filedir);  // search function, finds pattern
    // std::string set_pattern(std::string pat);
    //void getstring(std::string file); // get file to search
    //void setPattern(std::string pat);


private:


};


#endif //UNTITLED8_REGEX_H
