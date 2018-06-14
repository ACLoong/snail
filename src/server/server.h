//
// Created by WangQing on 14/06/2018.
//

#ifndef SNAIL_SERVER_H
#define SNAIL_SERVER_H

#include "boost/asio.hpp"

namespace snail {
    class Server {
    public:
        Server() = default;
        virtual ~Server() = default;
        int loop();
    private:

    };
}


#endif //SNAIL_SERVER_H
