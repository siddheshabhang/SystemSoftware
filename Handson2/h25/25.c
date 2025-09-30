/*
============================================================================
Name : 25.c
Author : Siddhesh Abhang.
Description : 
Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 29th September 2025
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
#include <unistd.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    key_t key = 1234;  // queue key
    int msqid;

    // Create message queue
    msqid = msgget(key, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }
    printf("Message queue created with ID = %d\n\n", msqid);

    // Send a message
    struct msgbuf msg;
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello from macOS!");
    if (msgsnd(msqid, &msg, sizeof(msg.mtext), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }
    printf("Message sent: %s\n\n", msg.mtext);

    // Receive a message
    struct msgbuf rmsg;
    if (msgrcv(msqid, &rmsg, sizeof(rmsg.mtext), 1, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }
    printf("Message received: %s\n\n", rmsg.mtext);

    // Print queue info
    struct msqid_ds buf;
    if (msgctl(msqid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("=== Message Queue Info ===\n");
    printf("Access permissions : %o\n", buf.msg_perm.mode);
    printf("UID : %d\n", buf.msg_perm.uid);
    printf("GID : %d\n", buf.msg_perm.gid);
    printf("Last msgsnd time   : %s", buf.msg_stime ? ctime(&buf.msg_stime) : "Not yet sent\n");
    printf("Last msgrcv time   : %s", buf.msg_rtime ? ctime(&buf.msg_rtime) : "Not yet received\n");
    printf("Last change time   : %s", ctime(&buf.msg_ctime));
    printf("Current queue size : %lu bytes\n", buf.msg_cbytes);
    printf("Number of messages : %lu\n", buf.msg_qnum);
    printf("Max bytes allowed  : %lu\n", buf.msg_qbytes);
    printf("PID of last msgsnd : %d\n", buf.msg_lspid);
    printf("PID of last msgrcv : %d\n", buf.msg_lrpid);

    // Optional: Delete the queue
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl delete");
        exit(1);
    }
    printf("\nMessage queue deleted.\n");

    return 0;
}

/*
============================================================================

Output:-
Message queue created with ID = 65536

Message sent: Hello from macOS!

Message received: Hello from macOS!

=== Message Queue Info ===
Access permissions : 666
UID : 501
GID : 20
Last msgsnd time   : Tue Sep 30 14:33:31 2025
Last msgrcv time   : Tue Sep 30 14:33:31 2025
Last change time   : Tue Sep 30 14:33:31 2025
Current queue size : 0 bytes
Number of messages : 0
Max bytes allowed  : 2048
PID of last msgsnd : 4645
PID of last msgrcv : 4645

Message queue deleted.

============================================================================
*/
