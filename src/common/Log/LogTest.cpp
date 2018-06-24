//
// Created by XFC on 2018/6/24.
//
#include <iostream>
#include <fstream>

#include "Log.h"
int main() {
    Log::addHandle([](const std::string &message) {
        std::cout << message << std::endl;
    }, false);

    Log::addHandle([](const std::string &message){

    }, true);

    Debug() << "hhhhhhh";
    return 0;
}
