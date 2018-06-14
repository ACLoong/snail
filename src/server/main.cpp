#include <iostream>

#include "server.h"

int main(int argc, char **argv) {
    snail::Server server;
    int ret = server.loop();

    return ret;
}