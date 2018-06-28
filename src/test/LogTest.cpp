//
// Created by XFC on 2018/6/24.
//
#include <iostream>
#include <fstream>
#include <thread>

#include "../common/Log/Log.h"
int main() {
    snail::log::LogContext context;
    snail::log::Log::setLogContext(&context);

    snail::log::Log::addHandle([](const std::string &message) {
        std::cout << message << std::endl;
    }, false);
    snail::log::Log::addHandle([](const std::string &message){
        std::ofstream f;
        f.open("/tmp/tmp.txt");
        f << message;
        f.close();
    }, true);

    snail::log::Log::setCacheSize(10);
    Debug() << "hhhhhhh";
    Error() << "dddddddddd";
    return 0;
}
