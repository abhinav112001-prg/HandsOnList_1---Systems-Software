/*
============================================================================================
Name: 08f.c
Author: Abhinav Sharma
Description: Write a separate program using signal system call to catch the following signals.
f. SIGVTALRM (setitimer system call)
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
}
int main () {
	signal(SIGVTALRM, signalHandler);

	struct itimerval timer;
	timer.it_value.tv_sec = 1;
	timer.it_value.tv_usec = 0;
	timer.it_interval.tv_sec = 1;
	timer.it_interval.tv_usec = 0;
	setitimer(ITIMER_VIRTUAL, &timer, NULL);

	for(;;)
	{
		for(int x=0; x<500000; x++);
		usleep(500000); // sleeps for 1/2 second
	}
	return 0;
}
/*
=======================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out

=======================================================================================================
*/
