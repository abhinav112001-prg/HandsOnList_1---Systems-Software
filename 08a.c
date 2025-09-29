/*
============================================================================================
Name: 08a.c
Author: Abhinav Sharma
Description: Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 21th September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void signalHandler(int signal) {
	printf("SIGNAL RECEIVED: %d\n", signal);
	exit(EXIT_FAILURE);
}
int main () {
	signal(SIGSEGV, signalHandler);
	int *ptr =NULL;
	int val = *ptr;
	printf("%d\n",val);
	printf("end of program.\n");
	return 0;
}
/*
=======================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out
SIGNAL RECEIVED: 11

=======================================================================================================
*/
