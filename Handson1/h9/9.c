/*
===================================================================================================================
Name: 9.c
Author: Siddhesh Abhang
Description:- 
Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 17 Aug 2025
===================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;

    if (stat(argv[1], &fileStat) < 0) {
        perror("stat");
        return 1;
    }

    printf("File: %s\n", argv[1]);
    printf("a. Inode: %ld\n", (long)fileStat.st_ino);
    printf("b. Number of hard links: %ld\n", (long)fileStat.st_nlink);
    printf("c. UID: %d\n", fileStat.st_uid);
    printf("d. GID: %d\n", fileStat.st_gid);
    printf("e. Size: %ld bytes\n", (long)fileStat.st_size);
    printf("f. Block size: %ld bytes\n", (long)fileStat.st_blksize);
    printf("g. Number of blocks: %ld\n", (long)fileStat.st_blocks);
    printf("h. Time of last access: %s", ctime(&fileStat.st_atime));
    printf("i. Time of last modification: %s", ctime(&fileStat.st_mtime));
    printf("j. Time of last change: %s", ctime(&fileStat.st_ctime));

    return 0;
}

/*
==================================================================================================================

Output:-
./output9 softlink                                                                                                                       ─╯
File: softlink
a. Inode: 47767657
b. Number of hard links: 2
c. UID: 501
d. GID: 20
e. Size: 339 bytes
f. Block size: 4096 bytes
g. Number of blocks: 8
h. Time of last access: Mon Sep  1 15:28:07 2025
i. Time of last modification: Mon Sep  1 15:24:37 2025
j. Time of last change: Mon Sep  1 15:28:06 2025

./output9 myfile.txt                                                                                                                     ─╯
File: myfile.txt
a. Inode: 47767657
b. Number of hard links: 2
c. UID: 501
d. GID: 20
e. Size: 339 bytes
f. Block size: 4096 bytes
g. Number of blocks: 8
h. Time of last access: Mon Sep  1 15:28:07 2025
i. Time of last modification: Mon Sep  1 15:24:37 2025
j. Time of last change: Mon Sep  1 15:28:06 2025

==================================================================================================================
*/
