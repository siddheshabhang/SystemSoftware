/*
============================================================================
Name : 22.c
Author : Siddhesh Abhang.
Description : 
Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 28th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>

#define FIFO_PATH "myfifo"

int main() {
    int fd;
    mkfifo(FIFO_PATH, 0666);   // create FIFO if not exists

    fd = open(FIFO_PATH, O_RDONLY | O_NONBLOCK);
    if (fd == -1) { perror("open"); exit(1); }

    fd_set readfds;
    struct timeval timeout;
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 10;   // wait max 10 seconds
    timeout.tv_usec = 0;

    printf("Waiting for data (10s)...\n");

    int ret = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
    } else if (ret == 0) {
        printf("Timeout! No data written.\n");
    } else {
        if (FD_ISSET(fd, &readfds)) {
            char buffer[100];
            int n = read(fd, buffer, sizeof(buffer) - 1);
            if (n > 0) {
                buffer[n] = '\0';
                printf("Received: %s\n", buffer);
            } else {
                printf("No data read (writer closed pipe).\n");
            }
        }
    }

    close(fd);
    return 0;
}

/*
============================================================================

Output:-
Waiting for data (10s)...
Received: Hello from Terminal 2

============================================================================
*/
