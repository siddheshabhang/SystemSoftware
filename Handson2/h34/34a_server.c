/*
============================================================================
Name : 34a_server.c
Author : Siddhesh Abhang
Description :
Write a program to create a concurrent server.
a. use fork
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);

    // Accept connection
    new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);
    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
    printf("Client connected.\n");

    // Fork for chat
    if (fork() == 0) {
        // Child: receive messages
        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int n = read(new_socket, buffer, BUFFER_SIZE);
            if (n <= 0) {
                printf("Client disconnected.\n");
                break;
            }
            printf("Client: %s", buffer);
        }
    } else {
        // Parent: send messages
        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            fgets(buffer, BUFFER_SIZE, stdin);
            write(new_socket, buffer, strlen(buffer));
        }
    }

    close(new_socket);
    close(server_fd);
    return 0;
}

/*
===================================================================================================================

Output:-
Server listening on port 8080...
Client connected.
Client: Hello from Client
Hello from Server
Client: Am I audible?
Yes

===================================================================================================================*/
