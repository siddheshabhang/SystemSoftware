/*
============================================================================
Name : 7.c
Author : Siddhesh Abhang.
Description:-
Write a simple program to print the created thread ids.
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <pthread.h>

// Thread function
void* thread_func(void* arg) {
    pthread_t tid = pthread_self();
    printf("Thread created with ID: %lu\n", tid);
    return NULL;
}

int main() {
    pthread_t threads[3];

    // Create three threads
    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
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
Thread created with ID: 6135590912
Thread created with ID: 6136164352
Thread created with ID: 6136737792

============================================================================
*/
