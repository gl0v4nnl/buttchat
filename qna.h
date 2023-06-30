#ifndef QNA_H
#define QNA_H

#include <string>
#include <map>

class qna {
    std::map<std::string, std::string> qmap = {
        {"exit", "bye"},
        {"start", "let's go"},
    };
    int count = 0;  
    int last_number = 1;  
public:
    bool add(std::string new_question, std::string new_answer);
    bool check(std::string check_string);
    bool remove(std::string rem_question);
};

#endif