/*
============================================================================
Name : 27a_sender.c
Author : Siddhesh Abhang.
Description : 
Write a program to receive messages from the message queue.
With 0 as a flag
Date: 29th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Define message structure
struct msgbuf {
    long mtype;        // Message type (>0)
    char mtext[100];   // Message text
};

int main() {
    int msqid;
    struct msgbuf msg;

    // Use a constant key
    key_t key = 1234;

    // Create or get message queue
    msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    //Prepare the message
    msg.mtype = 1;  // message type > 0
    strcpy(msg.mtext, "Hello from sender!");

   // Send message
    if (msgsnd(msqid, &msg, sizeof(msg.mtext), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent successfully. Queue ID = %d\n", msqid);
    return 0;
}

/*
============================================================================

Output:-
Message sent successfully. Queue ID = 196608

============================================================================
*/
