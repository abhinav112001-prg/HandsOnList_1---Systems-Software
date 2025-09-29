/*
============================================================================================
Name: 08c.c
Author: Abhinav Sharma
Description: Write a separate program using signal system call to catch the following signals.
c. SIGPE
Date: 21th September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
// SIGFPE       P1990      Core    Floating-point exception
void signalHandler(int signal) {
	printf("SIGNAL RECEIVED: %d\n", signal);
	exit(EXIT_FAILURE);
}
int main () {
	signal(SIGFPE, signalHandler);
	int a;
	a=3/0;
	printf("will this execute?");
	return 0;
}
/*
=======================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out
SIGNAL RECEIVED: 11

=======================================================================================================
*/
