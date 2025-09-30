/*
============================================================================
Name : 27a_receive.c
Author : Siddhesh Abhang.
Description:- 
Write a program to receive messages from the message queue.
With 0 as a flag
Date: 29th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
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

    // Use the same constant key as sender
    key_t key = 1234;

    // Connect to the existing message queue
    msqid = msgget(key, 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    //Receive first message in queue (FIFO)
    // msgtyp = 0 -> first message
    // msgflg = 0 -> blocking call
    if (msgrcv(msqid, &msg, sizeof(msg.mtext), 0, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }

    // Print received message
    printf("Message received: %s\n", msg.mtext);

    return 0;
}

/*
============================================================================

Output:-
Message received: Hello from sender!

============================================================================
*/
