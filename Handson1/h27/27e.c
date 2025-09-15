/*
===================================================================================================================
Name: 27e.c
Author: Siddhesh Abhang
Description:-
Write a program to execute ls -Rl by the execvp() syscall.
Date: 6 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing 'ls -Rl' using execvp...\n");

    char *args[] = {"ls", "-Rl", NULL};

    execvp("ls", args);

    perror("execvp failed");
    return 1;
}

/*
==================================================================================================================

Output:-
Executing 'ls -Rl' using execvp...
total 112
-rw-r--r--@ 1 siddheshabhang  staff    977  7 Sep 11:12 27a.c
-rw-r--r--@ 1 siddheshabhang  staff   1054  7 Sep 11:11 27b.c
-rw-r--r--@ 1 siddheshabhang  staff   1175  7 Sep 11:15 27c.c
-rw-r--r--@ 1 siddheshabhang  staff    854  7 Sep 11:16 27d.c
-rw-r--r--@ 1 siddheshabhang  staff    853  7 Sep 11:17 27e.c
-rwxr-xr-x@ 1 siddheshabhang  staff  33656  7 Sep 11:17 a.out

==================================================================================================================
*/

