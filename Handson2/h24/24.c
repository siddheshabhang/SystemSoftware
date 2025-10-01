/*
============================================================================
Name : 24.c
Author : Siddhesh Abhang.
Description:-  
Write a program to create a message queue and print the key and message queue id.
Date: 1st October 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    // Generate a unique key using ftok
    key = ftok("progfile", 65);   // "progfile" must exist
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Create a message queue with read/write permission
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // Print key and message queue id
    printf("Message Queue created successfully!\n");
    printf("Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

    return 0;
}

/*
============================================================================

Output:-
Message Queue created successfully!
Key: 1091503268
Message Queue ID: 262144

============================================================================
*/
