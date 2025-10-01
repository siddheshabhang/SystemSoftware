/*
============================================================================
Name : 32d.c
Author : Siddhesh Abhang
Description:-
Remove the previously created semaphore.
Date: 30th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    // Key used when creating the semaphore
    key_t sem_key = ftok(".", 65); 

    // Get semaphore ID
    int semid = semget(sem_key, 1, 0666);
    if (semid == -1) {
        perror("semget failed: semaphore may not exist");
        exit(1);
    }

    // Remove the semaphore
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl IPC_RMID failed");
        exit(1);
    }

    printf("Semaphore with ID %d removed successfully.\n", semid);
    return 0;
}

/*
============================================================================
Output:-
Semaphore with ID 458753 removed successfully.

============================================================================
*/
