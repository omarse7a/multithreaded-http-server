#include <iostream>
#include "Server.h"

using namespace std;

int main() {
    Server* server = new Server(80);
    server->run();
    return 0;
}