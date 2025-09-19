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

#include <unistd.h>   // read(), close()
#include <fcntl.h>    // open()
#include <stdlib.h>   // exit()
#include <stdio.h>    // printf(), perror()

#define BUFFER_SIZE 256

int main() {
    int fd;
    ssize_t bytesRead;
    char buffer[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    int lineIndex = 0;

    fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            if (buffer[i] == '\n') {                  line[lineIndex] = '\0';
                printf("%s\n", line);
                lineIndex = 0;
            } else {
                line[lineIndex++] = buffer[i];
            }
        }
    }

    if (lineIndex > 0) {
        line[lineIndex] = '\0';
        printf("%s\n", line);
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

