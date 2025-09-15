/*
===================================================================================================================
Name: 27a.c
Author: Siddhesh Abhang
Description:-
Write a program to execute ls -Rl by the execl() syscall.
Date: 6 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing command: ls -Rl\n");
;
    execl("/bin/ls", "ls", "-Rl", NULL);

     perror("execl failed");
    return 1;
}

/*
==================================================================================================================

Output:-
Executing command: ls -Rl
total 80
-rw-r--r--@ 1 siddheshabhang  staff    586  7 Sep 02:28 27a.c
-rwxr-xr-x@ 1 siddheshabhang  staff  33512  7 Sep 02:28 a.out

==================================================================================================================
*/
