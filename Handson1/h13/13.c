/*
===================================================================================================================
Name: 13.c
Author: Siddhesh Abhang
Description:- 
Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 19 Aug 2025
===================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    struct timeval timeout;
    int retval;

    FD_ZERO(&readfds); 
    FD_SET(STDIN_FILENO, &readfds);
    timeout.tv_sec = 10;       
    timeout.tv_usec = 0;

    printf("Waiting for input (10 seconds)...\n");

    retval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select()");
    } else if (retval == 0) {
        printf("No data within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            printf("Data is available! Type something:\n");
            char buffer[100];
            read(STDIN_FILENO, buffer, sizeof(buffer));
            printf("You typed: %s\n", buffer);
        }
    }

    return 0;
}

/*
==================================================================================================================

Output when data is available in 10 seconds:-
Waiting for input (10 seconds)...
Hello my name is Siddhesh
Data is available! Type something:
You typed: Hello my name is Siddhesh

Output if data not available in 10 seconds:-
Waiting for input (10 seconds)...
No data within 10 seconds.

==================================================================================================================
*/
