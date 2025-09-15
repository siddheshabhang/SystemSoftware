/*
===================================================================================================================
Name: 27c.c
Author: Siddhesh Abhang
Description:-
Write a program to execute ls -Rl by the execle() syscall.
Date: 6 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing 'ls -Rl' using execle...\n");

    char *env[] = {"PATH=/bin:/usr/bin", NULL};

    execle("/bin/ls", "ls", "-Rl", NULL, env);

    perror("execle failed");
    return 1;
}

/*
==================================================================================================================

Output:-
Executing 'ls -Rl' using execle...
total 96
-rw-r--r--@ 1 siddheshabhang  staff    977 Sep  7 11:12 27a.c
-rw-r--r--@ 1 siddheshabhang  staff   1054 Sep  7 11:11 27b.c
-rw-r--r--@ 1 siddheshabhang  staff    884 Sep  7 11:14 27c.c
-rwxr-xr-x@ 1 siddheshabhang  staff  33656 Sep  7 11:14 a.out

==================================================================================================================
*/

