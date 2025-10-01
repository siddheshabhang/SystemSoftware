/*
============================================================================
Name : 34b_server.c
Author : Siddhesh Abhang.
Description : 
Write a program to create a concurrent server.
b. use pthread_create
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int client_socket;

void* recv_func(void* arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int n = read(client_socket, buffer, BUFFER_SIZE);
        if (n <= 0) {
            printf("Client disconnected.\n");
            break;
        }
        printf("Client: %s", buffer);
    }
    return NULL;
}

void* send_func(void* arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        write(client_socket, buffer, strlen(buffer));
    }
    return NULL;
}

int main() {
    int server_fd;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("Socket failed"); exit(1); }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed"); exit(1);
    }

    listen(server_fd, 1);
    printf("Server listening on port %d...\n", PORT);

    client_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);
    if (client_socket < 0) { perror("Accept failed"); exit(1); }
    printf("Client connected.\n");

    pthread_t t1, t2;
    pthread_create(&t1, NULL, recv_func, NULL);
    pthread_create(&t2, NULL, send_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    close(client_socket);
    close(server_fd);
    return 0;
}

/*
=======================================================================================================================

Output:-
Server listening on port 8080...
Client connected.
Client: Hello I am Client. If you can hear me say Hi.
Hi

=======================================================================================================================*/
