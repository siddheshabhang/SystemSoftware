/*
============================================================================
Name : 18.c
Author : Siddhesh Abhang.
Description : 
Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 23th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2];
    pid_t p1, p2, p3;

    // Step 1: Create pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        exit(1);
    }

    // Step 2: First child -> "ls -l"
    if ((p1 = fork()) == 0) {
        dup2(pipe1[1], STDOUT_FILENO);   // redirect stdout -> pipe1 write
        close(pipe1[0]); close(pipe1[1]); // close unused ends
        close(pipe2[0]); close(pipe2[1]); // not used here

        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);
        perror("execvp ls");
        exit(1);
    }

    // Step 3: Second child -> "grep ^d"
    if ((p2 = fork()) == 0) {
        dup2(pipe1[0], STDIN_FILENO);    // stdin <- pipe1 read
        dup2(pipe2[1], STDOUT_FILENO);   // stdout -> pipe2 write
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);

        char *args[] = {"grep", "^d", NULL};
        execvp(args[0], args);
        perror("execvp grep");
        exit(1);
    }

    // Step 4: Third child -> "wc -l"
    if ((p3 = fork()) == 0) {
        dup2(pipe2[0], STDIN_FILENO);    // stdin <- pipe2 read
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);

        char *args[] = {"wc", "-l", NULL};
        execvp(args[0], args);
        perror("execvp wc");
        exit(1);
    }

    // Step 5: Parent closes everything and waits
    close(pipe1[0]); close(pipe1[1]);
    close(pipe2[0]); close(pipe2[1]);

    waitpid(p1, NULL, 0);
    waitpid(p2, NULL, 0);
    waitpid(p3, NULL, 0);

    return 0;
}

/*
============================================================================

Output for ll | grep ^d:-
ll | grep ^d                                                                         ─╯
drwxr-xr-x@    - siddheshabhang 23 Sep 21:58  tempdir1
drwxr-xr-x@    - siddheshabhang 23 Sep 21:58  tempdir2

Output of code:-
	2

============================================================================
*/
