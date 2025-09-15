/*
===================================================================================================================
Name: 1b.c
Author: Siddhesh Abhang
Description:-
Create the following types of a files using syscall
Hard link (link system call)
Date: 12 Aug 2025
===================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    if (link("tempfile.txt", "hardlink.txt") == -1) {
        perror("link failed");
    } else {
        printf("Hardlink created: hardlink.txt -> tempfile.txtt\n");
}
	return 0;
 }

/*
==================================================================================================================

Output:-
Hardlink created: hardlink.txt -> tempfile.txt

==================================================================================================================
*/

