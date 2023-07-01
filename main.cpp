//------------------------------------------------------------------------------
//
// WebSocket server, synchronous
//
//------------------------------------------------------------------------------

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <functional>
#include <string>
#include <thread>
#include <iostream>

#include "main.h"
#include "qna.h"

using tcp = boost::asio::ip::tcp;               // from <boost/asio/ip/tcp.hpp>
namespace websocket = boost::beast::websocket;  // from <boost/beast/websocket.hpp>
using namespace std;

// Echoes back all received WebSocket messages
void do_session(tcp::socket& socket) {
    try {
        websocket::stream<tcp::socket> ws{move(socket)};        // Construct the stream by moving in the socket
        ws.accept();                                            // Accept the websocket handshake

        for(;;) {
            boost::beast::multi_buffer buffer;                  // This buffer will hold the incoming message
            ws.read(buffer);                                    // Read a message
            ws.text(ws.got_text());                             // Echo the message back
            ws.write(buffer.data());
        }
    }

    catch(boost::system::system_error const& se) {
        if(se.code() != websocket::error::closed)               // This indicates that the session was closed
            cerr << "Error: " << se.code().message() << endl;
    }

    catch(exception const& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int main(int argc, char *argv[]) {
    /*qna bot;
    string question;
    
    while (true) {
        getline(cin, question);
        cout << bot.reply(question) << endl;
    }*/

/////////////////////////////////////////////////////////////////////////////////
    try {
        if (argc != 3) {                                        // Check command line arguments.
            cerr <<
                "Usage: buttchat <address> <port>\n" <<
                "Example:\n" <<
                "    buttchat 0.0.0.0 8080\n";
            return EXIT_FAILURE;
        }
        auto const address = boost::asio::ip::make_address(argv[1]);
        auto const port = static_cast<unsigned short>(atoi(argv[2]));

        boost::asio::io_context ioc{1};                         // The io_context is required for all I/O
        tcp::acceptor acceptor{ioc, {address, port}};           // The acceptor receives incoming connections

        for(;;) {
            tcp::socket socket{ioc};                            // This will receive the new connection
            acceptor.accept(socket);                            // Block until we get a connection
            thread{bind(&do_session,move(socket))}.detach();    // Launch the session, transferring ownership of the socket
        }
    }

    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return EXIT_FAILURE;
    }    
    
    return 0;
}
