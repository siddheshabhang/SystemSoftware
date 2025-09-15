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

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

struct ticket_db {
	int ticket_no;
};

int main()
{
	int fd;
	struct ticket_db db;
	
	db.ticket_no = 1000;
	
	fd = open("ticket_db", O_CREAT | O_RDWR, 0644);
	if(fd == -1)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	
	write(fd, &db, sizeof(db));
	close(fd);
	
	printf("Initialized ticket number to %d\n", db.ticket_no);
	return 0;
}

/*
==================================================================================================================

Output:-
Initialized ticket number to 1000

==================================================================================================================
*/
