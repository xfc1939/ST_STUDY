//
// Created by xfc on 2019/4/6.
//

#ifndef ST_APP_SERVER_H
#define ST_APP_SERVER_H

#include <string>

class Server {
public:
    Server();
    ~Server() = default;
    Server(const Server &rhs) = delete;

public:
    bool Init(const std::string &ip, int port);
    bool StartListen(int maxConnectNum);

private:
    int sockFd_;
};


#endif //ST_APP_SERVER_H
