/*
===================================================================================================================
Name: 17.c
Author: Siddhesh Abhang
Description:- 
Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. 
Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
Date: 2 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

struct ticket_db {
	int ticket_no;
};

int main()
{
	int fd;
	struct ticket_db db;
	struct flock lock;
	
	fd = open("ticket_db", O_RDWR);
	if(fd == -1)
	{
		perror("Error opening ticket file");
		exit(EXIT_FAILURE);
	}
	
	read(fd, &db, sizeof(db));
	
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	
	printf("Before entering critical section\n");
	fcntl(fd, F_SETLKW, &lock);
	printf("Lock acquired. Inside Critical Section...\n");
	
	lseek(fd, 0, SEEK_SET);
	read(fd, &db, sizeof(db));

	printf("Current ticket number: %d\n", db.ticket_no);
	db.ticket_no++;
	printf("New ticket number: %d\n", db.ticket_no);
	
	lseek(fd, 0, SEEK_SET);
	write(fd, &db, sizeof(db));

	printf("Enter any key to proceed and unlock..\n");
	getchar();

	write(fd, &db, sizeof(db));

	lock.l_type = F_UNLCK;
	printf("Unlocking file\n");
	fcntl(fd, F_SETLK, &lock);

	close(fd);
	
	return 0;
}

/*
==================================================================================================================

Output from terminal 1:-
Before entering critical section
Lock acquired. Inside Critical Section...
Current ticket number: 1001
New ticket number: 1002
Enter any key to proceed and unlock..

Output from terminal 2:-
Before entering critical section

==================================================================================================================
*/
