
/*
============================================================================================================
Name: 12.c
Author: Abhinav Sharma
Description: Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 28th September 2025
============================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include <sys/types.h>

void main(void) {
	pid_t child_pid = fork();
	
	if(child_pid > 0) { //parent process code
		printf("Parent process ID: %d\n",getpid());
		exit(0);
	}
	else if (child_pid == 0){ // child
		pid_t parentPID = getppid();
		printf("Child process ID: %d\n",getpid());
		sleep(5);
		// kill code!!
		kill(parentPID, SIGKILL);
		sleep(20);
	}
}