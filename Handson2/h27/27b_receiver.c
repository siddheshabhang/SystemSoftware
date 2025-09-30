/*
============================================================================
Name : 27.c
Author : Siddhesh Abhang.
Description : 
Write a program to receive messages from the message queue.
With IPC_NOWAIT as a flag
Date: 29th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    int msqid;
    struct msgbuf msg;
    key_t key = 1234;

    // Connect to existing queue
    msqid = msgget(key, 0666);
    if (msqid == -1) { perror("msgget"); exit(1); }

    // Receive first message (non-blocking)
    if (msgrcv(msqid, &msg, sizeof(msg.mtext), 0, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG)
            printf("No messages available in the queue.\n");
        else
            perror("msgrcv");
        exit(0);
    }

    // Print received message
    printf("Message received: %s\n", msg.mtext);

    return 0;
}

/*
============================================================================

Output:-
Message received: Hello with IPC_NOWAIT!

============================================================================
*/
