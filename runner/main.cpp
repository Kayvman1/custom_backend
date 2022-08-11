#include <iostream>
#include "../src/server/server.h"

int main(int argc, char const *argv[])
{ // server   //client

    int port_arg = 8080;
    if (argc == 2)
    {
        port_arg = atoi(argv[1]);
    }

    server *runner =  new server();

    runner->start(port_arg);
}