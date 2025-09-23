/*
============================================================================
Name : 19e.c
Author : Siddhesh Abhang.
Description : 
19. Create a FIFO file by mkfifo() library function
Date: 23th September 2025
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    if (mkfifo("myfifo_via_mkfifolibraryfunc", 0666) == -1) {
        perror("mkfifo error");
        return 1;
    }

    printf("FIFO file created successfully.\n");
    return 0;
}

/*
============================================================================

Output:-
FIFO file created successfully.

|rw-r--r--@    - siddheshabhang 23 Sep 22:39  myfifo_via_mkfifolibraryfunc

============================================================================
*/

