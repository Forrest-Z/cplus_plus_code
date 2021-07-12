/*
 UNIX Socket class
 written by Jared Bruni
*/

#ifndef __SOCKET__H___X
#define __SOCKET__H___X

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<iostream>
#include<string>
#include<sstream>
#include<unistd.h>
#include<fcntl.h>
#include<cstring>
#include<cstdio>
#include<signal.h>
#include<errno.h>

namespace net {
    
    enum class SocketType { STREAM, DGRAM };
    
    class Socket {
    public:
        Socket();
        Socket(int fd);
        Socket(const Socket &s);
        Socket(Socket &&s);
        Socket &operator=(const Socket &s);
        Socket &operator=(const Socket &&);
        void setSocket(const Socket &s);
        void setSocket(Socket &&s);
        int connectToIp(const std::string &host, const std::string &port, SocketType type);
        int connectToIp(const std::string &hostname, int port);
        int connectToHostName(const std::string &hostname, const std::string &port, SocketType type);
        int connectToHostName(const std::string &hostname, int port);
        int listenAt(const std::string &port, SocketType type, int backlog);
        bool valid() const { return (sockfd >= 0); }
        int &fd() { return sockfd; }
        int acceptSocket(Socket &s);
        int acceptSocket(Socket &s, sockaddr *addr, socklen_t *addrlen);
        ssize_t readLine(std::string &buf);
        ssize_t readHeader(std::string &buf);
        std::string readLine(ssize_t &bytesRead);
        ssize_t receive(void *buf, size_t len);
        ssize_t sendData(const void *buf, size_t len);
        ssize_t sendString(const std::string &text);
        int closeSocket();
        void setBlocking(bool state);
    private:
        int sockfd;
        socklen_t addrlen;
        bool blocking;
    };
    
    void ignorePipeSignal();
    bool convertHostToIp(const std::string &hostname , std::string &ip);
}

#endif
