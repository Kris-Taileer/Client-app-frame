#include "TCPclient.h"

using namespace std;
TCPclient::TCPclient(){
    sock = -1;
    port = 0;
    address = "";
}
bool TCPclient::setup(string address, int port) {
    if (sock == -1) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            cout << "Cannot create a socket, sorry dude\n";
        }
    }
    if (inet_addr(address.c_str()) == -1) {
        struct hostent *he;
        struct in_addr **addr_list;
        if ((he = gethostbyname(address.c_str())) == NULL) {
            herror("gethostbyname");
            cout << "failed to receive host name\n";
            return false;
        }
        addr_list = (struct in_addr **) he -> h_addr_list;
        for (int i=0; addr_list[i] != NULL; ++i){
            server.sin_addr = *addr_list[i];
            break;
        }

    } else {
        server.sin_addr.s_addr = inet_addr(address.c_str());
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (connect(sock, (struct sockaddr*) &server, sizeof(server)) < 0){
        perror("connection failed! ERROR");
        return false;
    }
    return true;
}
bool TCPclient::send(string data) {
    if (sock != -1) {
        if (send(sock, data.c_str(), strlen(data.c_str()), 0) < 0) {

        }
    }
}
string TCPclient::receive(){

}

void exit(){
    exit(0);

}
