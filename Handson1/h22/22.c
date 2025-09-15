/*
===================================================================================================================
Name: 22.c
Author: Siddhesh Abhang
Description:-
Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 3 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd;
    pid_t pid;

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
 
   if (fd < 0) {
        perror("open failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {

        const char *child_msg = "Hello from the child process!\n";
        write(fd, child_msg, sizeof("Hello from the child process!\n") - 1);
    }
    else {
        const char *parent_msg = "Hello from the parent process!\n";
        write(fd, parent_msg, sizeof("Hello from the parent process!\n") - 1);
    }

    close(fd);
	printf("Written to file successfully\n");
    return 0;
}
