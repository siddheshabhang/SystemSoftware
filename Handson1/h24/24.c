/*
===================================================================================================================
Name: 24.c
Author: Siddhesh Abhang
Description:-
Write a program to create an orphan process.
Date: 4 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	pid = fork();
	
	if(pid < 0)
	{
		perror("fork failed");
		return 1;
	}
	else if(pid == 0)
	{
		printf("Child process (PID = %d), Parent PID = %d\n", getpid(), getppid());
		sleep(5);
		printf("Child process (PID = %d) after sleeping, New Parent PID = %d\n", getpid(), getppid());
	}
	else
	{
		printf("Parent process (PID = %d) exiting...\n", getpid());
		exit(0);
	}
	return 0;
}

/*
==================================================================================================================

Output:-
Parent process (PID = 1821) exiting...
Child process (PID = 1822), Parent PID = 1821
Child process (PID = 1822) after sleeping, New Parent PID = 1

==================================================================================================================
*/

