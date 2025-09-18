/*
===================================================================================================================
Name: 7.c
Author: Siddhesh Abhang
Description:- 
Write a program to copy file1 into file2 ($cp file1 file2).
Date: 16 Aug 2025
===================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int fd_src, fd_dest;
	ssize_t bytesRead;
	char buffer[1024];
	
	fd_src = open("ogfile.txt", O_RDONLY);
	if(fd_src < 0)
	{
		write(2, strerror(errno), strlen(strerror(errno)));
		exit(1);
	}
	
	fd_dest = open("copyfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd_dest < 0)
	{
		write(2, strerror(errno), strlen(strerror(errno)));
		close(fd_src);
		exit(1);
	}

	while((bytesRead = read(fd_src, buffer, 1024)) > 0){
		if(write(fd_dest, buffer, bytesRead)!= bytesRead){
		write(2, "Write error\n", 12);
		close(fd_src);
		close(fd_dest);
		exit(1);
	}
	}
	if (bytesRead < 0) {
    write(2, "Read error\n", 11);
}
	close(fd_src);
close(fd_dest);
	return 0;

}

/*
==================================================================================================================

Content in sourcefile.txt:-
Linux System Programming by Robert Love is the best book for learning Linux.

Content in copyfile.txt:-

Output:-
File copied successfully.

Content in copyfile.txt:-
Linux System Programming by Robert Love is the best book for learning Linux.

==================================================================================================================
*/

