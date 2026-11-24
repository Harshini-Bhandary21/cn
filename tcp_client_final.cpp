
#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstdio>
using namespace std;
int main()
{
    int clientSocket;
    char buffer[1024] = {0};
    sockaddr_in serverAddr{};
    // Create TCP socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    // Server IP address
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
    // Connect to server
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("connect failed");
        return 1;
    }
    // Send message to server
    string msg = "Hello from TCP Client!";
    send(clientSocket, msg.c_str(), msg.length(), 0);
    // Receive server response
    recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    cout << "Server: " << buffer << endl;
    // Close socket
    close(clientSocket);
    return 0;
}
