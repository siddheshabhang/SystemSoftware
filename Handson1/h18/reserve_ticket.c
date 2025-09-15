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
#include <sys/types.h>

#define FILENAME "record_file.txt"

struct Record {
    int train_num;
    int ticket_count;
};

void lock_and_operate(int record_index, int is_write) {
    int fd = open(FILENAME, is_write ? O_RDWR : O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    struct Record record;
    struct flock lock = {0};
    lock.l_whence = SEEK_SET;
    lock.l_start = record_index * sizeof(struct Record);
    lock.l_len = sizeof(struct Record);
    lock.l_pid = getpid();
    lock.l_type = is_write ? F_WRLCK : F_RDLCK;

    printf("[Process %d] Trying to acquire %s lock on record %d...\n",
           getpid(), is_write ? "WRITE" : "READ", record_index + 1);

    fcntl(fd, F_SETLKW, &lock); 

    printf("[Process %d] Lock acquired on record %d.\n", getpid(), record_index + 1);

    lseek(fd, record_index * sizeof(struct Record), SEEK_SET);
    read(fd, &record, sizeof(struct Record));

    if (is_write) {
        printf("[Process %d] Current Ticket Count: %d\n", getpid(), record.ticket_count);

         sleep(10);

        record.ticket_count++;
        lseek(fd, -sizeof(struct Record), SEEK_CUR);
        write(fd, &record, sizeof(struct Record));

        printf("[Process %d] Ticket Count Updated to: %d\n", getpid(), record.ticket_count);
    } else {
        printf("[Process %d] Train Number: %d, Ticket Count: %d\n",
               getpid(), record.train_num, record.ticket_count);
    }

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("[Process %d] Lock released on record %d.\n", getpid(), record_index + 1);

    close(fd);
}

int main() {
    int choice, record_index;

    printf("Choose:\n1. Read Record\n2. Book Ticket (Increment Count)\nEnter choice: ");
    scanf("%d", &choice);

    printf("Select train number (1, 2, 3): ");
    scanf("%d", &record_index);

    if (record_index < 1 || record_index > 3 || (choice != 1 && choice != 2)) {
        printf("Invalid input.\n");
        return 1;
    }

    lock_and_operate(record_index - 1, choice == 2);

    return 0;
}

/*

Output from Terminal 1 while reading ticket_num from same Train as Terminal 2:-
Choose:
1. Read Record
2. Book Ticket (Increment Count)
Enter choice: 1
Select train number (1, 2, or 3): 2
[Process 21608] Trying to acquire READ lock on record 2...
[Process 21608] Lock acquired on record 2.
[Process 21608] Train Number: 2, Ticket Count: 0
[Process 21608] Lock released on record 2.

Output from Terminal 2 while reading ticket_num from same Train as Terminal 1:-
Choose:
1. Read Record
2. Book Ticket (Increment Count)
Enter choice: 1
Select train number (1, 2, or 3): 2
[Process 21608] Trying to acquire READ lock on record 2...
[Process 21608] Lock acquired on record 2.
[Process 21608] Train Number: 2, Ticket Count: 0
[Process 21608] Lock released on record 2.

###############################################################################################################

Output from Terminal 1 while booking ticket_num from same train as Terminal 2:-
Choose:
1. Read Record
2. Book Ticket (Increment Count)
Enter choice: 2
Select train number (1, 2, or 3): 3
[Process 21664] Trying to acquire WRITE lock on record 3...
[Process 21664] Lock acquired on record 3.
[Process 21664] Current Ticket Count: 3

Output from Terminal 2 while booking ticket_num from same train as Terminal 2:-
Choose:
1. Read Record
2. Book Ticket (Increment Count)
Enter choice: 2
Select train number (1, 2, or 3): 3
[Process 21654] Trying to acquire WRITE lock on record 3...

#################################################################################################################

Output from Terminal 1 while booking ticket_num from different train as Terminal 2:-
Choose:
1. Read Record
2. Book Ticket (Increment Count)
Enter choice: 2
Select train number (1, 2, or 3): 1
[Process 21716] Trying to acquire WRITE lock on record 1...
[Process 21716] Lock acquired on record 1.
[Process 21716] Current Ticket Count: 0
[Process 21716] Ticket Count Updated to: 1
[Process 21716] Lock released on record 1.

Output from Terminal 2 while booking ticket_num from different train as Terminal 1:-
Choose:
1. Read Record
2. Book Ticket (Increment Count)
Enter choice: 2
Select train number (1, 2, or 3): 2
[Process 21781] Trying to acquire WRITE lock on record 2...
[Process 21781] Lock acquired on record 2.
[Process 21781] Current Ticket Count: 0
[Process 21781] Ticket Count Updated to: 1
[Process 21781] Lock released on record 2.

==================================================================================================================
*/
