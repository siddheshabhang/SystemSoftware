/*
===================================================================================================================
Name: 1a.c
Author: Siddhesh Abhang
Description:-
Create the following types of a files using 
Soft link (symlink system call)
Date: 12 Aug 2025
===================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    if (symlink("tempfile.txt", "softlink.txt") == -1) {
        perror("symlink failed");
    } else {
        printf("Soft link created: softlink.txt -> tempfile.txt\n");
    }
    return 0;
}
