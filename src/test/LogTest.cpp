//
// Created by XFC on 2018/6/24.
//
#include <iostream>
#include <fstream>
#include <thread>
#include "common/Log/Log.h"
#include "minuint/minunint.h"

int main() {
    snail::LogContext context;
    snail::Log::setLogContext(&context);

    snail::Log::addHandler([](const std::string &message) {
        std::cout << message << std::endl;
    }, false);
    snail::Log::addHandler([](const std::string &message){
        std::ofstream f;
        f.open("/tmp/tmp.txt");
        f << message;
        f.close();
    }, true);

    snail::Log::setCacheSize(10);
    MU_RUN_SUITE(Debug);
    MU_REPORT();
    Debug() << "hhhhhhh";
    Error() << "dddddddddd";
    return 0;
}
