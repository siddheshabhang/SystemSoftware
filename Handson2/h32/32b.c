/*
============================================================================
Name : 32b.c
Author : Siddhesh Abhang
Description:-
Protect shared memory from concurrent write access using a binary semaphore.
Multiple processes can attach, but only one can write at a time.
Date: 30th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <string.h>

// Avoid redefinition of semun on macOS
#if !defined(__APPLE__) && !defined(__MACH__)
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
#endif

int main() {
    key_t shm_key = ftok(".", 65); // Key for shared memory
    key_t sem_key = ftok(".", 66); // Key for semaphore

    // 1. Create shared memory segment (1KB)
    int shmid = shmget(shm_key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    char *shared_mem = (char *)shmat(shmid, NULL, 0); // Attach
    if (shared_mem == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    // 2. Create binary semaphore
    int semid = semget(sem_key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget failed");
        exit(1);
    }

    // Initialize semaphore to 1
    union semun arg;
    arg.val = 1;
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("semctl SETVAL failed");
        exit(1);
    }

    // Semaphore operations
    struct sembuf p_op = {0, -1, 0}; // P() Wait
    struct sembuf v_op = {0, 1, 0};  // V() Signal

    // Simulate multiple writes to shared memory
    for (int i = 0; i < 5; i++) {
        // Wait (enter critical section)
        if (semop(semid, &p_op, 1) == -1) {
            perror("semop P failed");
            exit(1);
        }

        // Critical section: write to shared memory
        sprintf(shared_mem, "Process PID %d wrote ticket %d", getpid(), i + 1);
        printf("Shared memory updated: %s\n", shared_mem);
        sleep(1); // Simulate work

        // Signal (exit critical section)
        if (semop(semid, &v_op, 1) == -1) {
            perror("semop V failed");
            exit(1);
        }
    }

    // Detach shared memory
    if (shmdt(shared_mem) == -1) {
        perror("shmdt failed");
        exit(1);
    }

    // Optionally: remove shared memory and semaphore
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl IPC_RMID failed");
        exit(1);
    }

    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl IPC_RMID failed");
        exit(1);
    }

    printf("Shared memory and semaphore removed successfully.\n");
    return 0;
}

/*
============================================================================

Output:- 
Shared memory updated: Process PID 11457 wrote ticket 1
Shared memory updated: Process PID 11457 wrote ticket 2
Shared memory updated: Process PID 11457 wrote ticket 3
Shared memory updated: Process PID 11457 wrote ticket 4
Shared memory updated: Process PID 11457 wrote ticket 5
Shared memory and semaphore removed successfully.

============================================================================
*/
