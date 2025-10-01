/*
============================================================================
Name : 34b_client.c
Author: Siddhesh Abhang.
Description:- 
Write a program to create a concurrent server.
b. use pthread_create
Date: 1st October, 2025
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

int sockfd;

void* recv_func(void* arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int n = read(sockfd, buffer, BUFFER_SIZE);
        if (n <= 0) {
            printf("Server disconnected.\n");
            break;
        }
        printf("Server: %s", buffer);
    }
    return NULL;
}

void* send_func(void* arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        write(sockfd, buffer, strlen(buffer));
    }
    return NULL;
}

int main() {
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) { perror("Socket failed"); exit(1); }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connect failed"); exit(1);
    }
    printf("Connected to server.\n");

    pthread_t t1, t2;
    pthread_create(&t1, NULL, recv_func, NULL);
    pthread_create(&t2, NULL, send_func, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    close(sockfd);
    return 0;
}

/*
===================================================================================================================

Output:-
Connected to server.
Hello I am Client? If you can hear me say Hi.
Server: Hi

===================================================================================================================*/
