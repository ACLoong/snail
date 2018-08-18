//
// Created by WangQing on 14/06/2018.
//

#include "server.h"

namespace snail {
    void Server::DoAccept() {
        auto accept_handler = [](const boost::system::error_code &error,
                                 std::shared_ptr<SocketType> socket) {
            //TODO(qwang): TODO here.
        };

        acceptor_.async_accept(socket_, accept_handler);
    }
}