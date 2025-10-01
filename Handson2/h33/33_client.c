/*
============================================================================
Name : 33.c
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
    int sock;
    struct sockaddr_in addr;
    char buffer[100];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);

    printf("Enter server IP: ");
    scanf("%s", buffer);
    inet_pton(AF_INET, buffer, &addr.sin_addr);

    connect(sock, (struct sockaddr*)&addr, sizeof(addr));

    send(sock, "Hello from client", 17, 0);
    read(sock, buffer, sizeof(buffer));
    printf("Server: %s\n", buffer);

    close(sock);
    return 0;
}

/*
============================================================================

Output:-


============================================================================
*/
