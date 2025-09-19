
/*
============================================================================================
Name: 24.c
Author: Abhinav Sharma
Description: Write a program to create an orphan process.
Date: 6th September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main(void) {
	pid_t child_pid = fork();
	//parent process code
	if(child_pid > 0) {
		printf("Parent process ID: %d\n",getpid());
		exit(0);
	}
	else {
		printf("Child process ID: %d\n",getpid());
		sleep(30);
	}
}
/*
================================================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out &
[1] 7257
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ Parent process ID: 7257
Child process ID: 7258

[1]+  Done                    ./a.out
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ps -o pid,ppid,stat,comm -p 7258
    PID    PPID STAT COMMAND
   7258    1597 S    a.out
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ps -o pid,ppid,stat,comm -p 7257
    PID    PPID STAT COMMAND
================================================================================================================================
*/
