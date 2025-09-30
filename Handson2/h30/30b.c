/*
============================================================================
Name : 30b.c
Author : Siddhesh Abhang.
Description:-
Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.
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

    char *ptr = (char *)shmat(shmid, NULL, SHM_RDONLY); // Attach read-only
    if (ptr == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    printf("Data in shared memory (read-only): %s\n", ptr);

    printf("Trying to overwrite...\n");
    // ptr[0] = 'X'; // Uncomment to see bus error (cannot write to read-only)

    if (shmdt(ptr) == -1) {
        perror("shmdt failed");
        exit(1);
    }

    return 0;
}

/*
============================================================================

Output:-
Data in shared memory (read-only): Learning about shared memory :)
Trying to overwrite...

============================================================================
*/
