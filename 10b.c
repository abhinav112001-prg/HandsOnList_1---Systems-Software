/*
========================================================================================
Name: 10b.c
Author: Abhinav Sharma
Description: Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
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
    memset(&sigact, 0, sizeof(sigact));
	sigact.sa_handler = signalHandler;
    sigact.sa_flags = 0; // No special flags
    sigemptyset(&sigact.sa_mask);

	sigaction(SIGSEGV, &sigact, NULL);
    while(!getchar());
	printf("ENTER pressed.");
	return 0;
}
/*
====================================================================================================

====================================================================================================
*/
