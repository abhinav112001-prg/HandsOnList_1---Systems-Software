/*
============================================================================================
Name: 08e.c
Author: Abhinav Sharma
Description: Write a separate program using signal system call to catch the following signals.
e. SIGALRM (setitimer system call)
Date: 25th September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
void signalHandler(int signal) {
	printf("SIGNAL RECEIVED: %d\n", signal);
	
	exit(EXIT_FAILURE);
}
int main () {
	signal(SIGALRM, signalHandler);
	struct itimerval timer;
	timer.it_value.tv_sec = 3; // Initial expiration
	timer.it_value.tv_usec = 0; // Initial expiration
	timer.it_interval.tv_sec = 2; // No periodic interval
	timer.it_interval.tv_usec = 0;

	setitimer(ITIMER_REAL, &timer, NULL);
	pause();
//	for(int i=0;i<100000;i++);
	return 0;
}
/*
=======================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out

=======================================================================================================
*/
