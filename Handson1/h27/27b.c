/*
===================================================================================================================
Name: 27b.c
Author: Siddhesh Abhang
Description:-
Write a program to execute ls -Rl by the execlp() syscall.
Date: 6 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing 'ls -Rl' using execlp...\n");

    execlp("ls", "ls", "-Rl", NULL);

    perror("execlp failed");
    return 1;
}

/*
==================================================================================================================

Output:-
Executing 'ls -Rl' using execlp...
total 88
-rw-r--r--@ 1 siddheshabhang  staff    993  7 Sep 10:46 27a.c
-rw-r--r--@ 1 siddheshabhang  staff    581  7 Sep 11:09 27b.c
-rwxr-xr-x@ 1 siddheshabhang  staff  33512  7 Sep 11:09 a.out

==================================================================================================================
*/

