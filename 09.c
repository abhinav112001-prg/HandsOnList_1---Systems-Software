/*
========================================================================================
Name: 09.c
Author: Abhinav Sharma
Description: Write a program to ignore a SIGINT signal then reset the default action of
the SIGINT signal - Use signal system call.
Date: 27th September 2025
========================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void handler (int signal) {
	printf("hello signal %d",signal);
	exit(0);
}
int main(void) {

	signal(SIGINT, handler);
	printf("Catching SIGINT\n");
	sleep(3);
	printf("no signal within 3 seconds\n");

	signal(SIGINT, SIG_IGN); // handler to ignore signal
	printf("Ignoring SIGINT\n");
	sleep(3);
	printf("No SIGINT within 3 seconds\n");

	signal(SIGINT, SIG_DFL); // DEFAULT SIGNAL HANDLER
	printf("Default action for SIGINT\n");
	sleep(8);
	printf("No SIGINT within 8 seconds\n");
	return 0;
}
/*
====================================================================================================
Catching SIGINT
^Chello signal 2no signal within 3 seconds
Ignoring SIGINT
No SIGINT within 3 seconds
Default action for SIGINT
^X^C

====================================================================================================
*/
