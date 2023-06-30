#include <iostream>

#include "main.h"
#include "qna.h"

int main(int argc, char *argv[]) {
    qna uquest;
    std::string newq;
    bool exit = false;
    
    while (!exit) {
        getline(std::cin, newq);
        exit = uquest.check(newq);
    }
    
    return 0;
}