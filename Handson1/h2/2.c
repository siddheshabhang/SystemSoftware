/*
===================================================================================================================
Name: 2.c
Author: Siddhesh Abhang
Description:- 
Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 12 Aug 2025
===================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        printf("Running in background...\n");
        sleep(5);   
    }
    return 0;
}

/*
==================================================================================================================

Output:-
[1] 12632
Running in background...

Output after top -pid 12632 :-
Processes: 421 total, 3 running, 418 sleeping, 2279 threads            13:19:13
Load Avg: 1.85, 1.81, 2.05  CPU usage: 5.61% user, 4.6% sys, 90.32% idle
SharedLibs: 289M resident, 68M data, 60M linkedit.
MemRegions: 0 total, 0B resident, 197M private, 884M shared.
PhysMem: 7561M used (1195M wired, 3110M compressor), 73M unused.
VM: 177T vsize, 5703M framework vsize, 11331(0) swapins, 101840(0) swapouts.
Networks: packets: 2324006/1644M in, 1535981/1745M out.
Disks: 2812457/63G read, 1104872/32G written.

PID    COMMAND      %CPU TIME     #TH  #WQ  #POR MEM  PURG CMPR PGRP  PPID
12632  output2      0.0  00:00.00 1    0    11   961K 0B   0B   12632 12487

==================================================================================================================
*/
