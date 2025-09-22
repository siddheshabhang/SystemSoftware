/*
============================================================================
Name : 16.c
Author : Siddhesh Abhang.
Description : 
Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 22th September 2025
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int p2c[2], c2p[2];  // pipes: parent->child and child->parent
    pid_t pid;
    char buffer[100];

    // create both pipes
    if (pipe(p2c) == -1 || pipe(c2p) == -1) {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    else if (pid > 0) {
        // ----- Parent process -----
        close(p2c[0]);  // parent does not read from p2c
        close(c2p[1]);  // parent does not write to c2p

        printf("Parent PID: %d\n", getpid());
        printf("Child PID (from parent): %d\n", pid);

        // send message to child
        char msg1[] = "Hello Child";
        write(p2c[1], msg1, strlen(msg1)+1);

        // receive message from child
        read(c2p[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);

        close(p2c[1]);
        close(c2p[0]);
    }
    else {
        // ----- Child process -----
        close(p2c[1]);  // child does not write to p2c
        close(c2p[0]);  // child does not read from c2p

        printf("Child PID: %d\n", getpid());
        printf("Parent PID (from child): %d\n", getppid());

        // receive message from parent
        read(p2c[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        // send message to parent
        char msg2[] = "Hello Parent";
        write(c2p[1], msg2, strlen(msg2)+1);

        close(p2c[0]);
        close(c2p[1]);
    }

    return 0;
}

/*
============================================================================

Output:-
Parent PID: 45740
Child PID (from parent): 45742
Child PID: 45742
Parent PID (from child): 45740
Child received: Hello Child
Parent received: Hello Parent

============================================================================
*/
