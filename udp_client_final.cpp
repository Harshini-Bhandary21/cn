
#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
    int clientSocket;
    char buffer[1024] = {0};
    sockaddr_in serverAddr;
    socklen_t addrSize = sizeof(serverAddr);

    // Create UDP socket
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8081);

    // Server IP address
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    // Send message to server
    string msg = "Hello from UDP Client!";
    sendto(clientSocket, msg.c_str(), msg.length(), 0,
           (sockaddr*)&serverAddr, addrSize);

    // Receive response from server
    recvfrom(clientSocket, buffer, sizeof(buffer), 0,
             (sockaddr*)&serverAddr, &addrSize);
    cout << "Server: " << buffer << endl;
    // Close socket
    close(clientSocket);

    return 0;
}
