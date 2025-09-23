/*
============================================================================
Name : 19d.c
Author : Siddhesh Abhang.
Description : 
19. Create a FIFO file by mknod() system call
Date: 23th September 2025
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    if (mknod("myfifo_via_mknodsyscall", S_IFIFO | 0666, 0) == -1) {
        perror("mknod error");
        return 1;
    }

    printf("FIFO file created successfully.\n");
    return 0;
}
/*
============================================================================

Output:-
FIFO file created successfully.

|rw-r--r--@    - siddheshabhang 23 Sep 22:39  myfifo_via_mknodsyscall

============================================================================
*/
