/*
============================================================================================
Name: 28.c
Author: Abhinav Sharma
Description: Write a program to get maximum and minimum real time priority.
Date: 28th August 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include <sched.h>
void main(void) {
	int maxPriorityFIFO =  sched_get_priority_max(SCHED_FIFO);
	int minPriorityFIFO =  sched_get_priority_min(SCHED_FIFO);
	printf("Max FIFO priority = %d\n", maxPriorityFIFO);
	printf("Max FIFO priority = %d\n", minPriorityFIFO);
	int maxPriorityRR =  sched_get_priority_max(SCHED_RR);
	int minPriorityRR =  sched_get_priority_min(SCHED_RR);
	printf("Max RR priority = %d\n", maxPriorityRR);
	printf("Max RR priority = %d\n", minPriorityRR);

	int maxPriorityOther =  sched_get_priority_max(SCHED_OTHER);
	int minPriorityOther =  sched_get_priority_min(SCHED_OTHER);
	printf("Max Non Real-time priority = %d\n", maxPriorityOther);
	printf("Max Non Real-time priority = %d\n", minPriorityOther);
}
/*
============================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
Max FIFO priority = 99
Max FIFO priority = 1
Max RR priority = 99
Max RR priority = 1
Max Non Real-time priority = 0
Max Non Real-time priority = 0
============================================================================================
*/
