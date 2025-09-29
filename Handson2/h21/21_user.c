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
    char buffer[100];
    char reply[] = "PIN entered: 1234";

    // Open fifo1 for reading
    fd1 = open(fifo1, O_RDONLY);
    if (fd1 == -1) { perror("open fifo1"); exit(1); }

    // Read message from ATM
    read(fd1, buffer, sizeof(buffer));
    printf("User received: %s\n", buffer);
    close(fd1);

    // Open fifo2 for writing
    fd2 = open(fifo2, O_WRONLY);
    if (fd2 == -1) { perror("open fifo2"); exit(1); }

    // Send reply to ATM
    write(fd2, reply, strlen(reply)+1);
    printf("User sent: %s\n", reply);
    close(fd2);

    return 0;
}

/*
============================================================================

Output:-
User received: Please enter your PIN:
User sent: PIN entered: 1234

============================================================================
*/
