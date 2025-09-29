/*
============================================================================
Name : 20.c
Author : Siddhesh Abhang.
Description : 
Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 27th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    int fd;
    char *fifo = "atm_fifo";
    char message[] = "Please collect your cash.";

    // Open FIFO for writing
    fd = open(fifo, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    write(fd, message, strlen(message)+1);
    printf("ATM sent: %s\n", message);

    close(fd);
    return 0;
}

/*
============================================================================

Output from Terminal 1:-                                
ATM sent: Please collect your cash.

Output from Terminal 2:-
User received: Please collect your cash.

============================================================================
*/

