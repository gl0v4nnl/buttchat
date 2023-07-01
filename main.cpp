#include <iostream>
#include <boost/asio.hpp>

#include "main.h"
#include "qna.h"

int main(int argc, char *argv[]) {
    qna bot;
    std::string newq;
    //bool exit = false;
    
    while (true) {
        getline(std::cin, newq);
        cout << bot.reply(newq) << endl;
    }
    
    return 0;
}
