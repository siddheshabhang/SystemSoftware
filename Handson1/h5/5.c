/*
===================================================================================================================
Name: 5.c
Author: Siddhesh Abhang
Description:- 
Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: 12 Aug 2025
===================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>  
#include <unistd.h> 

int main() {
    int fd[5];
    int i;
    pid_t pid = getpid();
    printf("Process started with PID = %d\n", pid);

    for (i = 0; i < 5; i++) {
        char filename[20];
        sprintf(filename, "file%d.txt", i+1);

        fd[i] = open(filename, O_CREAT | O_WRONLY, 0644);
        if (fd[i] == -1) {
            perror("open failed");
            return 1;
        }
        printf("Created %s with FD = %d\n", filename, fd[i]);
    }

    while (1) {
        sleep(5);  
    }

    for (i = 0; i < 5; i++) {
        close(fd[i]);
    }

    return 0;
}

/*
==================================================================================================================

Output:-
[1] 15324
Process started with PID = 15324
Created file1.txt with FD = 3
Created file2.txt with FD = 4
Created file3.txt with FD = 5
Created file4.txt with FD = 6
Created file5.txt with FD = 7

Output after lsof -p 15184:-
COMMAND   PID           USER   FD   TYPE DEVICE SIZE/OFF                NODE NAME
output5 15324 siddheshabhang  cwd    DIR   1,18      352            45371487 /Users/siddheshabhang/Desktop/Linux/Handson1/h5
output5 15324 siddheshabhang  txt    REG   1,18    33784            48985657 /Users/siddheshabhang/Desktop/Linux/Handson1/h5/output5
output5 15324 siddheshabhang  txt    REG   1,18  2289328 1152921500312524573 /usr/lib/dyld
output5 15324 siddheshabhang    0u   CHR   16,0 0t689367                 855 /dev/ttys000
output5 15324 siddheshabhang    1u   CHR   16,0 0t689367                 855 /dev/ttys000
output5 15324 siddheshabhang    2u   CHR   16,0 0t689367                 855 /dev/ttys000
output5 15324 siddheshabhang    3w   REG   1,18        0            48985681 /Users/siddheshabhang/Desktop/Linux/Handson1/h5/file1.txt
output5 15324 siddheshabhang    4w   REG   1,18        0            48985682 /Users/siddheshabhang/Desktop/Linux/Handson1/h5/file2.txt
output5 15324 siddheshabhang    5w   REG   1,18        0            48985683 /Users/siddheshabhang/Desktop/Linux/Handson1/h5/file3.txt
output5 15324 siddheshabhang    6w   REG   1,18        0            48985684 /Users/siddheshabhang/Desktop/Linux/Handson1/h5/file4.txt
output5 15324 siddheshabhang    7w   REG   1,18        0            48985685 /Users/siddheshabhang/Desktop/Linux/Handson1/h5/file5.txt

==================================================================================================================
*/

