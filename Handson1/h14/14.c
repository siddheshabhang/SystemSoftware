/*
===================================================================================================================
Name: 14.c
Author: Siddhesh Abhang
Description:- 
Write a program to find the type of a file.
a. Input should be taken from command line.
b. Program should be able to identify any type of a file.
Date: 19 Aug 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;

     if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

     if (stat(argv[1], &fileStat) == -1) {
        perror("stat");
        return 1;
    }

     if (S_ISREG(fileStat.st_mode)) {
        printf("%s is a Regular File\n", argv[1]);
    } 
    else if (S_ISDIR(fileStat.st_mode)) {
        printf("%s is a Directory\n", argv[1]);
    } 
    else if (S_ISLNK(fileStat.st_mode)) {
        printf("%s is a Symbolic Link\n", argv[1]);
    } 
    else if (S_ISCHR(fileStat.st_mode)) {
        printf("%s is a Character Device\n", argv[1]);
    } 
    else if (S_ISBLK(fileStat.st_mode)) {
        printf("%s is a Block Device\n", argv[1]);
    } 
    else if (S_ISFIFO(fileStat.st_mode)) {
        printf("%s is a FIFO (named pipe)\n", argv[1]);
    } 
    else if (S_ISSOCK(fileStat.st_mode)) {
        printf("%s is a Socket\n", argv[1]);
    } 
    else {
        printf("Unknown file type\n");
    }

    return 0;
}

/*
==================================================================================================================

Output:-
./a.out Folder                                                                                                   ─╯
Folder is a Directory

./a.out test.txt                                                                                                 ─╯
test.txt is a Regular File

==================================================================================================================
*/

