//
// Created by WangQing on 19/08/2018.
//

#ifndef SNAIL_CLIENT_H
#define SNAIL_CLIENT_H

#include <boost/asio.h>

namespace snail {

class Client : public Channel {
public:

private:
    boost::asio::ip::tcp::socket socket_;
};

} // snail

#endif //SNAIL_CLIENT_H
