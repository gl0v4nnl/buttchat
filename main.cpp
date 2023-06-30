#include <iostream>

#include "main.h"
#include "qna.h"

int main(int argc, char *argv[]) {
    qna bot;
    std::string newq;
    bool exit = false;
    
    while (!exit) {
        getline(std::cin, newq);
        exit = bot.reply(newq);
    }
    
    return 0;
}
