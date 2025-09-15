/*
===================================================================================================================
Name: 6.c
Author: Siddhesh Abhang
Description:- 
Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 14 Aug 2025
===================================================================================================================
*/

#include <unistd.h>  
#include <stdlib.h>  
#include <errno.h>   
#include <string.h>  
#include <stdio.h>   

int main() {
    char buffer[1024];  
    ssize_t bytesRead;  

    bytesRead = read(0, buffer, sizeof(buffer));

    if (bytesRead < 0) {
        write(2, strerror(errno), strlen(strerror(errno)));
        write(2, "\n", 1);
        exit(1);
    }

    write(1, buffer, bytesRead);

    char msg[100];
    int len = sprintf(msg, "\nNumber of bytes read into buffer: %zd\n", bytesRead);
    write(1, msg, len);

    return 0;
}

/*
==================================================================================================================

Output:-
International Institute of Information Technology, Bengaluru
International Institute of Information Technology, Bengaluru

Number of bytes read into buffer: 61 

==================================================================================================================
*/
