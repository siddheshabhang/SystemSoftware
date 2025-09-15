/*
===================================================================================================================
Name: 16b.c
Author: Siddhesh Abhang
Description:- 
Write a program to perform mandatory locking
Implement read lock
Date: 2 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	int fd;
	struct flock lock;
	fd = open("testfile.txt", O_RDWR | O_CREAT, 0666);
	if (fd < 0) {
		perror("open");
		exit(1);
	}
	
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;

	printf("Trying to acquire read lock...\n");
	if (fcntl(fd, F_SETLK, &lock) == -1){
		perror("fcntl");
		exit(1);
	}
	
	printf("Read lock acquired. Press Enter to release...\n");
	getchar();
	
	lock.l_type = F_UNLCK;
	if (fcntl(fd , F_SETLK, &lock) == -1) {
		perror("fcntl");
		close(fd);
		exit(1);
	}

	printf("Lock released.\n");
	close(fd);
	return 0;
}

/*
==================================================================================================================

Output from Terminal 1:-
Trying to acquire read lock...
Read lock acquired. Press Enter to release...

Output from Terminal 2:-
Trying to acquire read lock...
Read lock acquired. Press Enter to release...

==================================================================================================================
*/

