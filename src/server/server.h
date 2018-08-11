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

        explicit Server(unsigned short port)
                : acceptor_(ioService_, EndpointType(boost::asio::ip::tcp::v4(), port)) {
            accept();
        }

        virtual ~Server() {
            //TODO(qwang): Do some cleanup.
        }

        void run() {
            ioService_.run();
        }

    private:
        void accept() {
            std::shared_ptr<SocketType> socket(std::make_shared<SocketType >(ioService_));
            using ErrorCodeType = boost::system::error_code;
            using SocketPtrType = std::shared_ptr<SocketType>;

            acceptor_.async_accept(*socket, [this](const ErrorCodeType &errorCode, SocketPtrType socket){
                //TODO(qwang): It may be not correct, errorCode is an object.
                if (errorCode) {
                    return ;
                }

                //TODO(qwang): Register the client into server.

                this->accept();
            });
        }

    private:
        boost::asio::io_service ioService_;
        AcceptorType acceptor_;
    };
}


#endif //SNAIL_SERVER_H
