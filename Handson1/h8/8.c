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

#include <unistd.h>  
#include <fcntl.h>   
#include <stdlib.h>  
#include <stdio.h>   

#define BUFFER_SIZE 256

int main() {
    int fd;
    ssize_t bytesRead;
    char ch;
    char line[BUFFER_SIZE];
    int lineIndex = 0;

    fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        write(2, "Error opening file\n", 19); 
        exit(1);
    }

    while ((bytesRead = read(fd, &ch, 1)) > 0) {
        if (ch == '\n') { 
            write(1, line, lineIndex);
            write(1, "\n", 1);
            lineIndex = 0;
        } else {
            line[lineIndex++] = ch;
        }
    }

    if (lineIndex > 0) {
        write(1, line, lineIndex);
        write(1, "\n", 1);
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

