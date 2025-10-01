/*
============================================================================
Name : 6.c
Author : Siddhesh Abhang.
Description:-
Write a simple program to create three threads.
system call. Use time stamp counter.
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <pthread.h>

// Thread function
void* thread_func(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d is running\n", id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3] = {1, 2, 3};

    // Create three threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

/*
============================================================================

Output:-
Thread 1 is running
Thread 2 is running
Thread 3 is running


============================================================================
*/
