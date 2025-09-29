/*
========================================================================================
Name: 10a.c
Author: Abhinav Sharma
Description: Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 27th September 2025
========================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void signalHandler(int signal) {
	printf("SIGNAL RECEIVED: %d\n", signal);
	exit(EXIT_FAILURE);
}
int main () {
	struct sigaction sigact;
    sigact.sa_handler = signalHandler;
    sigact.sa_flags = 0; // No special flags
    sigemptyset(&sigact.sa_mask);

	sigaction(SIGSEGV, &sigact, NULL);
    // if (sigaction(SIGVTALRM, &sa, NULL) == -1) {
    //     perror("sigaction");
    //     exit(EXIT_FAILURE);
    // }
	
	int *ptr =NULL;
	int val = *ptr;
	printf("%d\n",val);
	printf("end of program.\n");
	return 0;
}
/*
====================================================================================================

====================================================================================================
*/
