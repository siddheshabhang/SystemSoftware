/*
============================================================================
Name : 30c.c
Author : Siddhesh Abhang.
Description:-
Write a program to create a shared memory.
b. detach the shared memory
Date: 29th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok(".", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT); // Create if doesn't exist

    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    char *ptr = (char *)shmat(shmid, NULL, 0); // Attach
    if (ptr == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    if (shmdt(ptr) == -1) { // Detach
        perror("shmdt failed");
        exit(1);
    }

    printf("Shared memory detached successfully.\n");
    return 0;
}

/*
============================================================================

Output:-
Shared memory detached successfully.

============================================================================
*/
