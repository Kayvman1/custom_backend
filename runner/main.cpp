#include <iostream>
#include "../src/server/server.h"
#include <spdlog/spdlog.h>
#include <signal.h>

void sigpipe_handler(int unused)
{
    spdlog::error("SIGPIPE BROKEN CAUGHT");
}

int main(int argc, char const *argv[])
{ // server   //client

    signal(SIGPIPE, sigpipe_handler);
    int port_arg = 8080;
    if (argc == 2)
    {
        port_arg = atoi(argv[1]);
    }

    server *runner = new server();

    runner->start(port_arg);
}