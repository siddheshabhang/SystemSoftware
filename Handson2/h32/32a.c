/*
============================================================================
Name : 32a.c
Author : Siddhesh Abhang.
Description:-
Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
Date: 30th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

// Avoid redefinition of semun on macOS
#if !defined(__APPLE__) && !defined(__MACH__)
union semun {
    int val;                 // value for SETVAL
    struct semid_ds *buf;    // buffer for IPC_STAT, IPC_SET
    unsigned short *array;   // array for GETALL, SETALL
};
#endif

int main() {
    key_t key = ftok(".", 65); // Generate unique key
    int semid = semget(key, 1, 0666 | IPC_CREAT); // Create 1 semaphore
    if (semid == -1) {
        perror("semget failed");
        exit(1);
    }

    // Initialize binary semaphore to 1
    union semun arg;
    arg.val = 1;
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl SETVAL failed");
        exit(1);
    }

    int ticket = 0; // Shared ticket number

    // Semaphore operations: P() and V()
    struct sembuf p_op = {0, -1, 0}; // Wait (decrement)
    struct sembuf v_op = {0, 1, 0};  // Signal (increment)

    // Simulate multiple ticket generations
    for (int i = 0; i < 5; i++) {
        // Enter critical section
        if (semop(semid, &p_op, 1) == -1) {
            perror("semop P failed");
            exit(1);
        }

        // Critical section
        ticket++;
        printf("Ticket number generated: %d\n", ticket);
        sleep(1); // Simulate processing

        // Exit critical section
        if (semop(semid, &v_op, 1) == -1) {
            perror("semop V failed");
            exit(1);
        }
    }

    // Remove semaphore
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl IPC_RMID failed");
        exit(1);
    }

    printf("Semaphore removed successfully.\n");
    return 0;
}

/*
============================================================================

Output:-
Ticket number generated: 1
Ticket number generated: 2
Ticket number generated: 3
Ticket number generated: 4
Ticket number generated: 5
Semaphore removed successfully.

============================================================================
*/
