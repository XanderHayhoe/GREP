#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
// this will be an implementation of GREP using c++ and for windows
// first, we must create a REGEX function
#include "Regex.h"
 // [A-Za-z1-9]
// declarations
// i need to define a recursive function to split the search into subprocesses edit: jk no i dont
void parse(const std::string &regex_string, std::vector<std::pair<char, char>>& chars) {
    char start, end;
    for (int c = 0; c < regex_string.size(); c++) {
        if (regex_string[c] == '-') {
            chars.push_back(std::make_pair(regex_string[c-1], regex_string[c+1]));
        }
        }

    }
// take modified regex_string from getfile() and parse()
// search using Boyer-Moore Theorem -> search x distance
// ex. [A-Bn-o1-9], "5kdu194ndsAdnrAo7rgs"
// see 5, check behind, see null, iterate by 3 chars.
// see u, iterate by 3.
// see 4, check behind, see 9, iterate
// see s, iterate by 3.
// see o, o belongs to our pattern (it is an ascii value in our set of ascii values, it is index 1 of our vector<pair<char, char>>
// profit

// if i can build this function i nvidia 1B
int search(std::string search_string, const std::string &regex_string, std::vector<std::pair<char, char>>& chars){
    int similar = 0;
    int match_count = 0;
    for(int i = 0; i < search_string.size(); i++) {
        if(search_string[i] >= chars[i].first || search_string[i] <= chars[i].second) {
            similar++;
            if (similar == search_string.size()) {
                match_count++;
            }
        else {
            similar = 0;
        }

        }
        return match_count;
    }

}

std::string getfile(std::string filedir, std::string &search_string) {
    std::string str;
    std::ifstream file;
    file.open(filedir);
    if (file) {
        std::ostringstream ss;
        ss << file.rdbuf();

        search_string = ss.str();

    }
    return search_string;

}

int main(int argc, char *argv[]) {
    std::string search_string;
    std::string sample = "A-Za-z1-9";
    std::vector<std::pair<char, char>> chars;
    std::string regex_string = "";
    std::string file = "C:\\Users\\xande\\CLionProjects\\untitled8\\txt.txt";

    getfile(file, regex_string);

    // const std::string &regex_string, std::vector<std::pair<char, char>>& chars
    parse(regex_string, chars);
    // std::string search_string, const std::string &regex_s
    // string, std::vector<std::pair<char, char>>& chars
    std::cout << search(search_string, regex_string, chars) << std::endl;




// asserts
    /* assert(argc != 1);

    for (int i = 0; i < argc; i++) {
        std::cin >> *argv[i];
    }

    char begin[] = {'G', 'R', 'E', 'P', 'P', 'E', 'R'};
    for (int i = 0; i < 7; i++) {
        assert(*argv[i] != begin[i]);
    }
     */



    return 0;

}
