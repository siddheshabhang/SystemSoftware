/*
===================================================================================================================
Name: 18.c
Author: Siddhesh Abhang
Description:- 
Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 6 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FILENAME "record_file.txt"

struct Record {
    int train_num;
    int ticket_count;
};

int main() {
    int fd = open(FILENAME, O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    struct Record records[3];

    for (int i = 0; i < 3; i++) {
        records[i].train_num = i + 1;
        records[i].ticket_count = 0;
    }

    write(fd, records, sizeof(records)); 
    close(fd);

    printf("File initialized with 3 records.\n");
    return 0;
}

/*
==================================================================================================================

Output:-
File initialized with 3 records.

==================================================================================================================
*/
