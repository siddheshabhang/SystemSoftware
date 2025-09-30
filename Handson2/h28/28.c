/*
============================================================================
Name : 28.c
Author : Siddhesh Abhang.
Description:- 
Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 29th September 2025
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key = 1234;  // Key of existing queue
    int msqid;
    struct msqid_ds buf;

    // Connect to existing queue
    msqid = msgget(key, 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    // Get current queue info
    if (msgctl(msqid, IPC_STAT, &buf) == -1) {
        perror("msgctl IPC_STAT");
        exit(1);
    }

    printf("Current permissions: %o\n", buf.msg_perm.mode);

    // Change permission to 0644 (owner read/write, others read-only)
    buf.msg_perm.mode = 0644;

    // Update the queue
    if (msgctl(msqid, IPC_SET, &buf) == -1) {
        perror("msgctl IPC_SET");
        exit(1);
    }

    printf("Permissions updated successfully.\n");

    // Print new permissions
    if (msgctl(msqid, IPC_STAT, &buf) == -1) {
        perror("msgctl IPC_STAT");
        exit(1);
    }
    printf("New permissions: %o\n", buf.msg_perm.mode);

    return 0;
}

/*
============================================================================

Output:-
Current permissions: 666
Permissions updated successfully.
New permissions: 644

============================================================================
*/
