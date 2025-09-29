/*
============================================================================
Name : 21.c
Author : Siddhesh Abhang.
Description : 
Write two programs so that both can communicate by FIFO -Use two way communications.
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
    int fd1, fd2;
    char *fifo1 = "fifo1"; // ATM -> User
    char *fifo2 = "fifo2"; // User -> ATM
    char message[] = "Please enter your PIN:";
    char buffer[100];

    // Open fifo1 for writing
    fd1 = open(fifo1, O_WRONLY);
    if (fd1 == -1) { perror("open fifo1"); exit(1); }

    // Send message to User
    write(fd1, message, strlen(message)+1);
    printf("ATM sent: %s\n", message);
    close(fd1);

    // Open fifo2 for reading
    fd2 = open(fifo2, O_RDONLY);
    if (fd2 == -1) { perror("open fifo2"); exit(1); }

    // Read reply from User
    read(fd2, buffer, sizeof(buffer));
    printf("ATM received: %s\n", buffer);
    close(fd2);

    return 0;
}

/*
============================================================================

Output:-
ATM sent: Please enter your PIN:
ATM received: PIN entered: 1234

============================================================================
*/
