/*
===================================================================================================================
Name: 8.c
Author: Siddhesh Abhang
Description:- 
Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 16 Aug 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>    

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(STDERR_FILENO, "Usage: ./a.out <filename>\n", 27);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[1024];
    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0';     
        write(STDOUT_FILENO, buffer, bytesRead); 
    }

    if (bytesRead == -1) {
        perror("Read error");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}

/*
==================================================================================================================

Output:-
The lantern flickered against the damp stone walls, casting long shadows that seemed alive. Somewhere in the distance, water dripped rhythmically, echoing like a heartbeat. Mira tightened her grip on the old brass key, unsure whether it would unlock a door or a memory she had tried to forget. Outside, the storm raged, rattling windows and bending trees, but inside the forgotten chamber, time stood still. A single book lay on the pedestal, its cover blank, yet the pages whispered faintly when the wind passed through the cracks in the wall.

==================================================================================================================
*/

