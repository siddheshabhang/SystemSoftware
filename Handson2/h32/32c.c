/*
============================================================================
Name : 32c.c
Author : Siddhesh Abhang.
Description:-
Protect multiple pseudo-resources (2) using a counting semaphore.
Multiple processes can access resources, but not more than available.
Date: 30th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

#if !defined(__APPLE__) && !defined(__MACH__)
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
#endif

int main() {
    key_t sem_key = ftok(".", 67); // Unique key
    int semid = semget(sem_key, 1, 0666 | IPC_CREAT); // Create 1 semaphore
    if (semid == -1) {
        perror("semget failed");
        exit(1);
    }

    // Initialize counting semaphore to 2 (2 resources)
    union semun arg;
    arg.val = 2;
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl SETVAL failed");
        exit(1);
    }

    // Semaphore operations
    struct sembuf p = {0, -1, 0}; // P() Wait
    struct sembuf v = {0, 1, 0};  // V() Signal

    // Simulate 5 accesses to resources
    for (int i = 0; i < 5; i++) {
        // Wait (try to acquire resource)
        if (semop(semid, &p, 1) == -1) {
            perror("semop P failed");
            exit(1);
        }

        // Critical section: pseudo resource usage
        printf("Process PID %d using a resource (%d/%d used)\n", getpid(), i+1, 2);
        sleep(1); // Simulate resource usage

        // Signal (release resource)
        if (semop(semid, &v, 1) == -1) {
            perror("semop V failed");
            exit(1);
        }
    }

    // Remove semaphore
    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl IPC_RMID failed");
        exit(1);
    }

    printf("Counting semaphore removed successfully.\n");
    return 0;
}

/*
============================================================================

Output:-
Process PID 11561 using a resource (1/2 used)
Process PID 11561 using a resource (2/2 used)
Process PID 11561 using a resource (3/2 used)
Process PID 11561 using a resource (4/2 used)
Process PID 11561 using a resource (5/2 used)
Counting semaphore removed successfully.

============================================================================
*/
