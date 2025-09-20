/*
================================================================================
Name: 02.c
Author: Abhinav Sharma
Description: Write a program to print the system resource limits. Use getrlimit system call.
Date: 20th September 2025
================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/resource.h>
void printLimits(int res) {
	struct rlimit lim;
	getrlimit(res, &lim);
	if(lim.rlim_cur == RLIM_INFINITY) {printf("Soft = Unlimited, ");}
	else {printf("Soft Limit = %lu, ",lim.rlim_cur);}

	if(lim.rlim_max == RLIM_INFINITY) {printf("Hard = Unlimited\n");}
	else {printf("Hard Limit = %lu\n",lim.rlim_max);}

}
int main(void){

	printf("Virtual memory/address space (bytes): ");
	printLimits(RLIMIT_AS);
printf("\n");
	printf("Core file size (bytes): ");
	printLimits(RLIMIT_CORE);
printf("\n");
	printf("CPU time per process (seconds): ");
	printLimits(RLIMIT_CPU);
printf("\n");
	printf("Process data segment (bytes): ");
	printLimits(RLIMIT_DATA);
printf("\n");
	printf("Max File size crerated by process (bytes): ");
	printLimits(RLIMIT_FSIZE);
printf("\n");
	printf("Combined flock locks and fcntl leases: ");
	printLimits(RLIMIT_LOCKS);
printf("\n");
	printf("Max Memory locked into RAM (bytes):");
	printLimits(RLIMIT_MEMLOCK);
printf("\n");
	printf("No of max bytes for message queues: ");
	printLimits(RLIMIT_MSGQUEUE);
printf("\n");
	printf("Ceiling to process's nice value: ");
	printLimits(RLIMIT_NICE);
printf("\n");
	printf("maximum  fd number can be opened by process: ");
	printLimits(RLIMIT_NOFILE);
printf("\n");
	printf("Number of extant process: ");
	printLimits(RLIMIT_NPROC);
printf("\n");
	printf("max real-time priority: ");
	printLimits(RLIMIT_RTPRIO);
printf("\n");
	printf("max real-time process' CPU time (microsec): ");
	printLimits(RLIMIT_RTTIME);
printf("\n");
	printf("Max number of signals queued: ");
	printLimits(RLIMIT_SIGPENDING);
printf("\n");
	printf("Process stack size (bytes): ");
	printLimits(RLIMIT_STACK);
printf("\n");

}



/*
==========================================================================================
Virtual memory/address space (bytes): Soft = Unlimited, Hard = Unlimited

Core file size (bytes): Soft Limit = 0, Hard = Unlimited

CPU time per process (seconds): Soft = Unlimited, Hard = Unlimited

Process data segment (bytes): Soft = Unlimited, Hard = Unlimited

Max File size crerated by process (bytes): Soft = Unlimited, Hard = Unlimited

Combined flock locks and fcntl leases: Soft = Unlimited, Hard = Unlimited

Max Memory locked into RAM (bytes):Soft Limit = 2071007232, Hard Limit = 2071007232

No of max bytes for message queues: Soft Limit = 819200, Hard Limit = 819200

Ceiling to process's nice value: Soft Limit = 0, Hard Limit = 0

maximum  fd number can be opened by process: Soft Limit = 1024, Hard Limit = 1048576

Number of extant process: Soft Limit = 62909, Hard Limit = 62909

max real-time priority: Soft Limit = 0, Hard Limit = 0

max real-time process' CPU time (microsec): Soft = Unlimited, Hard = Unlimited

Max number of signals queued: Soft Limit = 62909, Hard Limit = 62909

Process stack size (bytes): Soft Limit = 8388608, Hard = Unlimited
==========================================================================================
*/
