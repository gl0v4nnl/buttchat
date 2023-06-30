#include "qna.h"
#include <iostream>
#include <iterator>


bool qna::add(std::string new_question, std::string new_answer) {
    int ret = false;
    if (qmap.find(new_question) != qmap.end()) {
        qmap.insert({new_question, new_answer});
        ret = true;
    }

    return ret;
}

bool qna::check(std::string check_string) {
    bool ret = false;
    auto iter = qmap.find(check_string);
    if (iter != qmap.end()) {
        std::cout << iter->second << std::endl;
        if (iter->first == "exit") 
            ret = true;
    }

    return ret;
}

bool qna::remove(std::string rem_question) {
    int ret = false;
    if (qmap.find(rem_question) != qmap.end()) {
        qmap.erase(rem_question);
        ret = true;
    }
    
    return ret;
}