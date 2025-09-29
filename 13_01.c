
/*
============================================================================================================
Name: 13_01.c
Author: Abhinav Sharma
Description: Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 29th September 2025
============================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
/*this program is the signal receiver*/
void signalHandler(int sig){
	printf("Caught signal: %d",sig);
}
void main(void) {
	signal(SIGINT, signalHandler);
	printf("Process ID: %d\n",getpid());
	printf("WAITING FOR SIGNAL\n");
	while(1) pause();
}
/*
============================================================================================================
compiling as sig_receiver

abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ cc 13_01.c -o sig_receiver
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ cc 13_02.c -o sig_sender
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./sig_receiver 
Process ID: 8848
WAITING FOR SIGNAL

[1]+  Stopped                 ./sig_receiver

============================================================================================================
*/