/*
===================================================================================================================
Name: 30.c
Author: Siddhesh Abhang
Description:- 
Write a program to run a script at a specific time using a Daemon process.
Date: 6 Sept 2025
===================================================================================================================
*/

#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define SCRIPT_PATH "/Users/siddheshabhang/Desktop/Linux/Handson1/h30/script.sh"
#define LOG_FILE    "/tmp/daemon_output.log"
#define ERROR_LOG   "/tmp/daemon_error.log"

void run_script() {
    execl("/bin/bash", "bash", SCRIPT_PATH, NULL);
    perror("execl failed");
    exit(1);
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        printf("Daemon started with PID: %d\n", pid);
        exit(EXIT_SUCCESS);    
	 }

       if (setsid() < 0) {
        perror("setsid failed");
        exit(EXIT_FAILURE);
    }

    freopen("/dev/null", "r", stdin);
    freopen(LOG_FILE, "a", stdout);
    freopen(ERROR_LOG, "a", stderr);

    while (1) {
        time_t now = time(NULL);
        struct tm *tm_info = localtime(&now);

        if (tm_info->tm_hour == 12 && tm_info->tm_min == 28) {
            printf("[%s] Time matched! Running script...\n", asctime(tm_info));
		fflush(stdout);
            run_script();
		
            sleep(60);
        }

        sleep(10); 
    }

    return 0;
}
/*
==================================================================================================================

Output:-                                                                                    ─╯
Daemon started with PID: 10305

Output after ps aux:-
siddheshabhang   10305   0.0  0.0 410743568   1312   ??  Ss   12:26PM   0:00.00 ./daemon_runner

Output from script file at 12:28 pm:-
[Sun Sep  7 12:28:09 2025
] Time matched! Running script...
Hello I am talking from the script!
 _____________________________________
/ All things are either sacred or     \
| profane. The former to ecclesiasts  |
| bring gain; The latter to the devil |
\ appertain. -- Dumbo Omohundro       /
 -------------------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||

==================================================================================================================
*/

