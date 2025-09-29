/*
=============================================================================================================
Name: 11.c
Author: Abhinav Sharma
Description: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 28th September 2025
=============================================================================================================
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

	struct sigaction sa;

	sa.sa_handler = handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	printf("Catching SIGINT\n");
	sleep(3);
	printf("no signal within 3 seconds\n");

	sa.sa_handler = SIG_IGN;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL); // handler to ignore signal
	printf("Ignoring SIGINT\n");
	sleep(3);
	printf("No SIGINT within 3 seconds\n");

	sa.sa_handler = SIG_DFL;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL); // DEFAULT SIGNAL HANDLER
	printf("Default action for SIGINT\n");
	sleep(3);
	printf("No SIGINT within 3 seconds\n");

}
/*
==========================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out
Catching SIGINT
^Chello signal 2abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out
Catching SIGINT
no signal within 3 seconds
Ignoring SIGINT
^C^CNo SIGINT within 3 seconds
Default action for SIGINT
^C
==========================================================================
*/