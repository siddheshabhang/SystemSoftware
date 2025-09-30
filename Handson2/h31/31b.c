/*
============================================================================
Name : 31b.c
Author : Siddhesh Abhang.
Description:-
Write a program to create a semaphore and initialize value to the semaphore.
b. Counting Semaphore
Date: 30th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok(".", 65); // Unique key
    int semid;

    // 1. Create a semaphore set with 1 semaphore
    semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget failed");
        exit(1);
    }

    // 2. Initialize counting semaphore to a value, e.g., 5
    union semun arg;
    arg.val = 5; // Initial count = 5
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl SETVAL failed");
        exit(1);
    }

    printf("Counting semaphore created with ID: %d and initial value: %d\n", semid, arg.val);

    return 0;
}

/*
============================================================================

Output:-
Counting semaphore created with ID: 65536 and initial value: 5

Output after ipcs -s:-
IPC status from <running system> as of Tue Sep 30 23:44:47 IST 2025
T     ID     KEY        MODE       OWNER    GROUP
Semaphores:
s  65536 0x410fe254 --ra-ra-ra- siddheshabhang    staff

============================================================================
*/
