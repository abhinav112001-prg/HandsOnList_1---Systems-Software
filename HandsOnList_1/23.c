/*
============================================================================================
Name: 23.c
Author: Abhinav Sharma
Description: Write a program to create a Zombie state of the running program.
Date: 6th September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void) {
	pid_t child_pid = fork();
	//parent process code
	if(child_pid > 0) {
		printf("Parent process ID: %d\n",getpid());
		sleep(30); //goes to sleep for 30 seconds
	}
	else {
		printf("Child process ID: %d\n",getpid());
		exit(0); //finishes execution early
	}
}
/*
====================================================================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ Parent process ID: 6882
Child process ID: 6883

abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ top -p 6883


top - 21:59:36 up 57 min,  2 users,  load average: 0.34, 0.41, 0.48
Tasks:   1 total,   0 running,   0 sleeping,   0 stopped,   1 zombie
%Cpu(s):  1.4 us,  0.9 sy,  0.0 ni, 97.6 id,  0.1 wa,  0.0 hi,  0.1 si,  0.0 st
MiB Mem :  15800.6 total,  11761.5 free,   2139.7 used,   2110.5 buff/cache
MiB Swap:   4096.0 total,   4096.0 free,      0.0 used.  13660.8 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND     
   6883 abhinav+  20   0       0      0      0 Z   0.0   0.0   0:00.00 a.out
===================================================================================================================================================
*/
