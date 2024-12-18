#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<vector>

using namespace std;

class TCPclient {
    private:

    int sock;
    string address;
    int port;
    struct sockaddr_in server;

    public:
    TCPclient();
    bool setup(string address, int port);
    string receive();
    bool send(string data);
    //string receive(int size = 4096);
    string read();
    void exit();

};


#endif
