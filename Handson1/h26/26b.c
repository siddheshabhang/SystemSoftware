/*
===================================================================================================================
Name: 26b.c
Author: Siddhesh Abhang
Description:-
Write a program to execute an executable program.
Pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 5 Sept 2025
===================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char num1[20], num2[20];

    printf("Enter first number: ");
    scanf("%19s", num1);

    printf("Enter second number: ");
    scanf("%19s", num2);

    printf("Launcher: Now executing './target %s %s'\n", num1, num2);


    execl("./target", "target", num1, num2, NULL);


    perror("execl failed");
    return 1;
}

/*
==================================================================================================================

Output:-
Enter first number: 16
Enter second number: 19
Launcher: Now executing './target 16 19'
Target Program: The sum of 16 and 19 is 35

==================================================================================================================
*/
