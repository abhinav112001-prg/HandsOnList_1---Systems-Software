
/*
============================================================================================================
Name: 13_02.c
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
/*this program is the signal sender*/

void main(void) {
	pid_t pid;
	printf("Enter PID to send signal to: ");
	scanf("%d",&pid);
	kill(pid, SIGSTOP);
	printf("SIGSTOP SENT!\n");
	
}
/*
============================================================================================================
compiling as sig_sender

abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./sig_sender 
Enter PID to send signal to: 8848
SIGSTOP SENT!

============================================================================================================
*/