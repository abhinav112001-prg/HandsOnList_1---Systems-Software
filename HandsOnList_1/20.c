/*
============================================================================================
Name: 20.c
Author: Abhinav Sharma
Description: Find out the priority of your running program. Modify the priority with nice command.
Date: 5th September 2025
============================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
int main(void) {
	int processID = getpid();
	int old_priority;
	old_priority = getpriority(PRIO_PROCESS, 0);
	printf("Process ID = %d\nInitial priority: %d.\n",processID,old_priority);

	sleep(3);
	int x;
	x = nice(5);
	int new_priority;
	new_priority = getpriority(PRIO_PROCESS, 0);
	if(old_priority != new_priority) {
	printf("Priority changed!\n");
	printf("New priority = %d.\n",new_priority);
	}
	else {
	printf("Priority NOT changed!\n");
	}

	sleep(3);
	x = nice(9);
	new_priority = getpriority(PRIO_PROCESS, 0);
	if(old_priority != new_priority) {
	printf("Priority changed!\n");
	printf("New priority = %d.\n",new_priority);
	}
	else {
	printf("Priority NOT changed!\n");
	}
}
/*
==================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out 
Process ID = 5597
Initial priority: 0.
Priority changed!
New priority = 5.
Priority changed!
New priority = 14.
==================================================================================================
*/
