//
// Created by xfc on 2019/4/6.
//

#include "Server.h"
#include "../define.h"
#include <arpa/inet.h>

#include <unistd.h>

Server::Server()
    : sockFd_(-1)
{

}

bool Server::Init(const std::string &ip, int port) {
    if (ip.empty() || port <= 0) {
        ERROR_EXIT("ip or port is invaild!");
        return false;
    }

    struct sockaddr_in serverAddr;

    std::cout << __FUNCTION__ << " ip is " << ip << " port is " << port << std::endl;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(ip.c_str());
    serverAddr.sin_port = htons(port);

    std::cout << __FUNCTION__ << " create socket " << std::endl;

    if ((sockFd_ = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        //ERROR_EXIT("create sock err");
        return false;
    }

    std::cout << __FUNCTION__ << " bind sock" << std::endl;

    if(bind(sockFd_, (struct sockaddr*)(&serverAddr), sizeof(serverAddr)) < 0) {
        ERROR_EXIT("bind error");
        return false;
    }
    return true;
}

bool Server::StartListen(int maxConnectNum) {
    if (listen(sockFd_, maxConnectNum) == -1) {
        ERROR_EXIT("listen failed");
    }

    int clientFd;
    struct sockaddr_in clientAddr;
    char buff[4096];
    int n;
    while(1) {
        if (clientFd = accept(sockFd_, NULL, NULL) == -1) {
            std::cout << __FUNCTION__ << "client fd error" << std::endl;
            continue;
        }
        std::cout << "123" << getpid() << std::endl;
        n = recv(clientFd, buff, 4096, 0);
        std::cout << __FUNCTION__ << " n is " << n << std::endl;
    }
}