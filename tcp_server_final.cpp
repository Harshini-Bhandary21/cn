
#include <iostream>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstdio>

using namespace std;

int main()
{
    int serverSocket, clientSocket;
    char buffer[1024] = {0};
    sockaddr_in serverAddr{}, clientAddr{};
    socklen_t addrSize = sizeof(clientAddr);
    // Create TCP socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) { perror("socket failed"); return 1; }
    int opt = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    // Bind socket to port 8080
    if (::bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    { perror("bind failed"); return 1; }
    // Listen for client
    if (listen(serverSocket, 5) < 0) { perror("listen failed"); return 1; }
    cout << "TCP Server waiting for client..." << endl;
    // Accept client connection
    clientSocket = accept(serverSocket,(sockaddr*)&clientAddr, &addrSize);
    cout << "Client connected!" << endl;
    // Receive message from client
    recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    cout << "Client: " << buffer << endl;
    // Send response to client
    string msg = "Hello from TCP Server!";
    send(clientSocket, msg.c_str(), msg.length(), 0);

    // Close sockets
    close(clientSocket);
    close(serverSocket);
    return 0;
}
