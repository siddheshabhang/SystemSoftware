/*
============================================================================
Name : 26.c
Author : Siddhesh Abhang.
Description : 
Write a program to send messages to the message queue. Check $ipcs -q
Date: 29th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Message structure
struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    key_t key;
    int msgid;
    struct msgbuf message;

    // 1. Generate unique key
    key = ftok("progfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // 2. Create or get message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    // 3. Prepare message
    message.mtype = 1;  // type must be > 0
    strcpy(message.mtext, "Hello, this is a test message!");

    // 4. Send message
    if (msgsnd(msgid, &message, sizeof(message.mtext), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent successfully.\n");
    return 0;
}

/*
============================================================================

Output(Verification with ipcs -q):-
IPC status from <running system> as of Tue Sep 30 16:05:11 IST 2025
T     ID     KEY        MODE       OWNER    GROUP
Message Queues:
q 131072 0x410fab76 --rw-rw-rw- siddheshabhang    staff

Output:-
Message sent successfully.

============================================================================
*/
