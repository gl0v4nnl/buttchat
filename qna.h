#ifndef QNA_H
#define QNA_H

#include <string>
#include <map>

class qna {
    std::map<std::string, std::string> qmap = {
        {"exit", "bye"},
        {"start", "let's go"},
        {"hello", "hi"},
    };
    int count = 0;  
    const int last_number = 3;  
public:
    bool add(std::string new_question, std::string new_answer);
    bool reply(std::string check_string);
    bool remove(std::string rem_question);
};

#endif
