#include<iostream>
#include<signal.h>
#include "TCPclient.h"

using namespace std;

TCPclient tcp;

void prog_exit(int a) {
    tcp.exit();
    exit(0);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, prog_exit);
    tcp.setup("127.0.0.1", 11999);

    while(1){
        srand(time(NULL));
        tcp.send(to_string(rand()));
        string res = receive();

        if (res != ""){
            cout << "Server Responce: " << res << "\n";
        } else {
            cout << "There's no response from server, check data that u gave\n";
        }
        sleep(1);
    }

    return 0;
}