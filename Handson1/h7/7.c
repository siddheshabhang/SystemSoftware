/*
===================================================================================================================
Name: 7.c
Author: Siddhesh Abhang
Description:- 
Write a program to copy file1 into file2 ($cp file1 file2).
Date: 16 Aug 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src, *dest;
    char ch;

    src = fopen("sourcefile.txt", "r");
    if (src == NULL) {
        printf("Error: Cannot open sourcefile.txt\n");
        return 1;
    }

    dest = fopen("copyfile.txt", "w");
    if (dest == NULL) {
        printf("Error: Cannot open copyfile.txt\n");
        fclose(src);
        return 1;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully.\n");

    fclose(src);
    fclose(dest);

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

