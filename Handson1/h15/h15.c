/*
===================================================================================================================
Name: 15.c
Author: Siddhesh Abhang
Description:- 
Write a program to display the environmental variable of the user (use environ).
Date: 22 Aug 2025
===================================================================================================================
*/
#include <stdio.h>

extern char **environ;  

int main() {
    char **env = environ;

    printf("Environment variables:\n\n");

    for (int i = 0; env[i] != NULL; i++) {
        printf("%s\n", env[i]);
    }

    return 0;
}

/*
==================================================================================================================

Output:-
Environment variables:

TERM_SESSION_ID=w0t0p0:264A154F-262A-4E2F-90CF-D1B11F0ECD11
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.MPFoyvzuks/Listeners
LC_TERMINAL_VERSION=3.5.5
COLORFGBG=15;0
ITERM_PROFILE=Default
XPC_FLAGS=0x0
LANG=en_IN.UTF-8
PWD=/Users/siddheshabhang/Desktop/Linux/Handson1/h15
==================================================================================================================

/*
