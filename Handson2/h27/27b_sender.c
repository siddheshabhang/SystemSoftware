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
#include <string.h>
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

    // Create or get queue
    msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) { perror("msgget"); exit(1); }

    // Prepare message
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello with IPC_NOWAIT!");

    // Send message
    if (msgsnd(msqid, &msg, sizeof(msg.mtext), 0) == -1) { perror("msgsnd"); exit(1); }

    printf("Message sent successfully.\n");
    return 0;
}

/*
============================================================================

Output:-
Message sent successfully.

============================================================================
*/
