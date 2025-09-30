/*
============================================================================
Name : 29.c
Author : Siddhesh Abhang.
Description:- 
Write a program to remove the message queue.
Date: 29th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = 1234;  // Key of the message queue
    int msqid;

    // Connect to the existing queue
    msqid = msgget(key, 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    // Remove the message queue
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID");
        exit(1);
    }

    printf("Message queue with ID %d removed successfully.\n", msqid);

    return 0;
}

/*
============================================================================

Output:-
Message queue with ID 196608 removed successfully.

Output after ipcs -q:-
IPC status from <running system> as of Tue Sep 30 17:00:34 IST 2025
T     ID     KEY        MODE       OWNER    GROUP
Message Queues:

============================================================================
*/
