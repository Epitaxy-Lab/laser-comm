#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

#define LASER_IP "169.254.12.13"

using namespace std;

int main(void){
    int sock;
    struct sockaddr_in server_addr;
    char laser_comm[100];

    memset(laser_comm, '\0', sizeof(laser_comm));

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock < 0){
        cout << "Socket failure.\n";
        return -1;
    }

    cout << "Socket success.\n";

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    server_addr.sin_addr.s_addr = inet_addr(LASER_IP);

    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        cout << "Conection Faliure.\n";
        return -1;
    }

    cout << "Connection Success!\n";

    while(1){
        cout << "Enter message: ";
        string message;
        std::getline(cin, message);
        //cin >> noskipws >> message >> skipws;
        //cout << "\n";
        if(message == "x"){
            close(sock);
            printf("Socket closed\n");  
            break;
        }
        message.append("\n");
        //message[len] = '\n'; message[len+1] = '\n';message[len+2] = '\0';


        if(send(sock, message.c_str(), message.length(), 0) < 0){
            cout << "Message failure.\n";
            return -1;
        }

        int read = recv(sock, laser_comm, sizeof(laser_comm), 0);

        if(read < 0){
            cout << "Reception Failure.\n";
            return -1;
        }
        laser_comm[read] = '\0';

        cout << "Response Received: " << laser_comm << "\n";
    }

    return 0;
}
