//
// Created by XFC on 2018/6/24.
//
#include <iostream>
#include <fstream>
#include <thread>

#include "Log.h"
int main() {
    std::cout << "hhhhhhh"<< std::endl;
    snail::log::Log::addHandle([](const std::string &message) {
        std::cout << message << std::endl;
    }, false);
    std::cout << "hhhhhhhhh" << std::endl;
    snail::log::Log::addHandle([](const std::string &message){
        std::ofstream f;
        f.open("/tmp/tmp.txt");
        f << message;
        f.close();
    }, true);
    std::cout << "hhhhhhhhhhhhhhhhhh";
    snail::log::Log::setCacheSize(10);
    std::cout << "hhhhhhhhhhhhhhhhhh";
    Debug() << "hhhhhhh";
    Debug() << "dddddddddd";
    return 0;
}
