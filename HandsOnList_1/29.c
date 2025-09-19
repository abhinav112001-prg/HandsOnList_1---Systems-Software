/*
============================================================================================
Name: 29.c
Author: Abhinav Sharma
Description: Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR).
Date: 6th September 2025
============================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sched.h>
void printSchedulingPolicy(int x) {
	switch (x) {
	        case SCHED_OTHER:
	            printf("Policy: SCHED_OTHER (Standard time-sharing)\n");
	            break;
	        case SCHED_FIFO:
	            printf("Policy: SCHED_FIFO (Real-time First-In, First-Out)\n");
	            break;
	        case SCHED_RR:
        	    printf("Policy: SCHED_RR (Real-time Round-Robin)\n");
	            break;

	        default:
	            printf("Policy: Unknown (%d)\n", x);
        	    break;
    	}
}
int main(void) {
	////
	pid_t pId = getpid();
	struct sched_param sp;
	int init_sched = sched_getscheduler(pId);
	printSchedulingPolicy(init_sched);

	sp.sched_priority = 55;
	int n;
	int new_policy = SCHED_RR;
	n = sched_setscheduler(pId, new_policy, &sp);
	printf("Policy successfully changed.\n");
        printSchedulingPolicy(sched_getscheduler(pId));

	return 0;
}
/*
============================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ sudo ./a.out
[sudo] password for abhinav-sharma: 
Policy: SCHED_OTHER (Standard time-sharing)
Policy successfully changed.
Policy: SCHED_RR (Real-time Round-Robin)
============================================================================================================
*/
