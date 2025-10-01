/*
============================================================================
Name : 34a_client.c
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
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    printf("Connected to server.\n");

    if (fork() == 0) {
        // Child: receive messages
        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int n = read(sockfd, buffer, BUFFER_SIZE);
            if (n <= 0) {
                printf("Server disconnected.\n");
                break;
            }
            printf("Server: %s", buffer);
        }
    } else {
        // Parent: send messages
        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            fgets(buffer, BUFFER_SIZE, stdin);
            write(sockfd, buffer, strlen(buffer));
        }
    }

    close(sockfd);
    return 0;
}

/*
===================================================================================================================

Output:-
Connected to server.
Hello from Client
Server: Hello from Server
Am I audible?
Server: Yes
Server disconnected.

===================================================================================================================*/
