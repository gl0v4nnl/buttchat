#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>

#include "qna.h"
using namespace std;

string tmp_string;

void qna::split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        words.push_back(item);
    }
}

bool qna::add(string new_question, string new_answer) {
    int ret = false;
    if (qmap.find(new_question) != qmap.end()) {
        qmap.insert({new_question, new_answer});
        ret = true;
    }

    return ret;
}

string qna::reply(string text) {
    tmp_string.clear();
#if 0
    split(text, ' ');

    for (auto word : words) {    
        auto iter = qmap.find(word);

        if (iter != qmap.end()) {
            cout << iter->second << ::endl;
            count++;
            if (iter->first == "exit") {
                ret = true;
            }
        }
    }

    words.clear();
#else
    for (auto element : qmap) {
        regex phrase(".*" + element.first + ".*");
        
        if (regex_match(text, phrase)) {
            cout << element.second << endl;
            if (element.first == "exit") {
                string tmp = element.second;
                tmp_string.push_back(*(char *)tmp.c_str());
            }
        }
    }
#endif
    return tmp_string;
}

bool qna::remove(string rem_question) {
    int ret = false;
    if (qmap.find(rem_question) != qmap.end()) {
        qmap.erase(rem_question);
        ret = true;
    }
    
    return ret;
}
