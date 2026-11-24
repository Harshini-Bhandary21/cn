
#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
    int serverSocket;
    char buffer[1024] = {0};
    sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize = sizeof(clientAddr);

    // Create UDP socket
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);

    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8081);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    bind(serverSocket,
         (sockaddr*)&serverAddr,
         sizeof(serverAddr));
    cout << "UDP Server waiting for messages..." << endl;

    // Receive message from client
    recvfrom(serverSocket, buffer, sizeof(buffer), 0,
             (sockaddr*)&clientAddr, &addrSize);

    cout << "Client: " << buffer << endl;

    // Send response to client
    string msg = "Hello from UDP Server!";
    sendto(serverSocket, msg.c_str(), msg.length(), 0,
           (sockaddr*)&clientAddr, addrSize);
    // Close socket
    close(serverSocket);

    return 0;
}
