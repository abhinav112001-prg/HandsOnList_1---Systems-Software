/*
================================================================================
Name: 03.c
Author: Abhinav Sharma
Description: Write a program to print the system resource limits. Use getrlimit system call.
Date: 20th September 2025
================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/resource.h>

void setAndPrintLimits(int res) {
	struct rlimit lim, newlim;
	getrlimit(res, &lim);

	printf("OLDER LIMITS: \n");
	if(lim.rlim_cur == RLIM_INFINITY) {printf("Soft = Unlimited, ");}
	else {printf("Soft Limit = %lu, ",lim.rlim_cur);}
	if(lim.rlim_max == RLIM_INFINITY) {printf("Hard = Unlimited\n");}
	else {printf("Hard Limit = %lu\n",lim.rlim_max);}

	lim.rlim_cur = 999;

	setrlimit(res, &lim);
	printf("NEW LIMITS: \n");
	getrlimit(res, &newlim);
	if(newlim.rlim_cur == RLIM_INFINITY) {printf("Soft = Unlimited, ");}
	else {printf("Soft Limit = %lu, ",newlim.rlim_cur);}
	if(newlim.rlim_max == RLIM_INFINITY) {printf("Hard = Unlimited\n");}
	else {printf("Hard Limit = %lu\n",newlim.rlim_max);}
}
int main(void){
	printf("Max number of signals queued: \n");
	setAndPrintLimits(RLIMIT_SIGPENDING);
	printf("\n");

}



/*
==========================================================================================

abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out
Max number of signals queued: 
OLDER LIMITS: 
Soft Limit = 62909, Hard Limit = 62909
NEW LIMITS: 
Soft Limit = 999, Hard Limit = 62909


==========================================================================================
*/
