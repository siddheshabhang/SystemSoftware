/*
============================================================================
Name : 30d.c
Author : Siddhesh Abhang.
Description:-
Write a program to create a shared memory.
d. remove the shared memory
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

    if (shmctl(shmid, IPC_RMID, NULL) == -1) { // Remove segment
        perror("shmctl failed");
        exit(1);
    }

    printf("Shared memory removed successfully.\n");
    return 0;
}
/*
============================================================================

Output:-
Shared memory removed successfully.

============================================================================
*/
