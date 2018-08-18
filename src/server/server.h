//
// Created by WangQing on 14/06/2018.
//

#ifndef SNAIL_SERVER_H
#define SNAIL_SERVER_H

#include "boost/asio.hpp"
#include "boost/asio/ip/tcp.hpp"

namespace snail {
    class Server {
    public:
        using AcceptorType = boost::asio::ip::tcp::acceptor;
        using EndpointType = boost::asio::ip::tcp::endpoint;
        using SocketType = boost::asio::ip::tcp::socket;

        Server(boost::asio::io_service io_service, unsigned short port)
                :io_service_(io_service),
                 acceptor_(io_service,
                           EndpointType(boost::asio::ip::tcp::v4(), 0)),
                 socket_(io_service) {
            DoAccept();
        }

        virtual ~Server() = default;


    private:
        void DoAccept();

    private:
        boost::asio::io_service &io_service_;
        AcceptorType acceptor_;
        SocketType socket_;
    };
}


#endif //SNAIL_SERVER_H
