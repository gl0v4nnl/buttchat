#ifndef QNA_H
#define QNA_H

#include <string>
#include <vector>
#include <regex>
#include <map>

using namespace std;

class qna {
    map<string, string> qmap = {
        {"exit", "bye"},
        {"start", "let's go"},
        {"hello", "hi"},
        {"how (are you|is it going)", "Alright"},
        {"who are you", "I'm a Buttman"},
    };
    int count = 0;  
    const int last_number = 3; 
    vector<string> words;

    void split(const string &s, char delim);
public:
    bool add(string new_question, string new_answer);
    bool reply(string text);
    bool remove(string rem_question);
};

#endif
