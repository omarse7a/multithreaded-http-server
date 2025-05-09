#include <iostream>
#include "Server.h"

using namespace std;

int main() {
    try {
        Server* server = new Server(7777);
        server->run();
    }
    catch (ConnectionFailedException& e) {
        cerr << "New Connection Failed:" << e.what();
    }
    catch (ConnectionRefusedException& e) {
        cerr << "New Connection Refused:" << e.what();
    }
    catch (std::runtime_error& e) {
        cerr << "Failed Server Init: " << e.what();
        exit(1);
    }

    return 0;
}