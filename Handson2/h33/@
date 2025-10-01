/*
============================================================================
Name : 33_server.c
Author : Siddhesh Abhang.
Description:-
Write a program to communicate between two machines using socket.
Date: 30th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[100];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 1);

    printf("Server listening...\n");
    client_fd = accept(server_fd, NULL, NULL);

    read(client_fd, buffer, sizeof(buffer));
    printf("Client: %s\n", buffer);

    send(client_fd, "Hello from server", 17, 0);

    close(client_fd);
    close(server_fd);
    return 0;
}

/*
============================================================================

Output:-


============================================================================
*/
