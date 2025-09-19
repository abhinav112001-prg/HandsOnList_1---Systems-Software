/*
============================================================================================
Name: 25.c
Author: Abhinav Sharma
Description: Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
Date: 28th August 2025
============================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
void main(void) {
	pid_t p1, p2, p3;
    	pid_t waited_pid;
	p1 = fork();
	if (p1==0) {
        	printf("Child 1 (PID = %d) running\n", getpid());
        	sleep(3);
        	printf("Child 1 (PID = %d) exiting\n", getpid());
        	exit(10);
	}


	p2 = fork();
	if (p2==0) {
        	printf("Child 2 (PID = %d) running\n", getpid());
        	sleep(5);
	        printf("Child 2 (PID = %d) exiting\n", getpid());
	        exit(20);
	}


	p3 = fork();
	if (p3==0) {
        	printf("Child 3 (PID = %d) running\n", getpid());
        	sleep(8);
        	printf("Child 3 (PID = %d) exiting\n", getpid());
        	exit(30);
    	}

	int status;
	printf("Parent waiting for Child 2 (PID = %d)\n", p2);
	waited_pid = waitpid(p2, &status, 0);

	if (waited_pid > 0) {
        	if (WIFEXITED(status)) {
        		printf("Parent: Child 2 exited with status %d\n", WEXITSTATUS(status));
        	}
	}
	wait(NULL);
	wait(NULL);
	printf("Parent (PID = %d) exiting\n", getpid());
}
/*
==============================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out 
Child 1 (PID = 4460) running
Child 2 (PID = 4461) running
Parent waiting for Child 2 (PID = 4461)
Child 3 (PID = 4462) running
Child 1 (PID = 4460) exiting
Child 2 (PID = 4461) exiting
Parent: Child 2 exited with status 20
Child 3 (PID = 4462) exiting
Parent (PID = 4459) exiting
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ 
==============================================================================================================
*/
