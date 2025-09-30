/*
============================================================================
Name : 30a.c
Author : Siddhesh Abhang.
Description:- 
Write a program to create a shared memory.
a. write some data to the shared memory
Date: 29th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok(".", 65);                      // Unique key
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT); // Create 1KB segment if not exists

    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    char *ptr = (char *)shmat(shmid, NULL, 0);     // Attach read/write
    if (ptr == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    strcpy(ptr, "Learning about shared memory :)"); // Write data
    printf("Data written: %s\n", ptr);

    if (shmdt(ptr) == -1) {                        // Detach
        perror("shmdt failed");
        exit(1);
    }

    return 0;
}

/*
============================================================================

Output:-
Data written: Learning about shared memory :)

============================================================================
*/
