/*
===================================================================================================================
Name: 26a.c
Author: Siddhesh Abhang
Description:-
Write a program to execute an executable program.
Use some executable program.
Date: 5 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Current process (PID = %d) is going to run 'cal'\n", getpid());

    if (execl("/usr/bin/cal", "cal", NULL) == -1) {
        perror("execl failed");
        exit(1);
    }

     printf("This line will not be printed if execl succeeds.\n");

    return 0;
}

/*
==================================================================================================================

Output:-
Current process (PID = 6145) is going to run 'cal'
   September 2025
Su Mo Tu We Th Fr Sa
    1  2  3  4  5  6
 7  8  9 10 11 12 13
14 15 16 17 18 19 20
21 22 23 24 25 26 27
28 29 30

==================================================================================================================
*/
