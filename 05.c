/*
============================================================================================
Name: 05.c
Author: Abhinav Sharma
Description: Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 21th September 2025
============================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<limits.h>
int main(void) {
	long int a = sysconf(_SC_ARG_MAX);
	printf("Max length of the arguments to the exec family of functions: %ld\n",a);
	a = sysconf(_SC_CHILD_MAX);
	printf("Max number of simultaneous process per user id: 	     %ld\n",a);
	a = sysconf(_SC_CLK_TCK);
	printf("Number of clock ticks (jiffy) per second:		     %ld\n",a);
	a = sysconf(_SC_OPEN_MAX);
	printf("Max number of open files by a process: 			     %ld\n",a);
	a = sysconf(_SC_PAGESIZE);
	printf("Size of a page: 					     %ld\n",a);
	a = sysconf(_SC_PHYS_PAGES);
	printf("total number of pages in the physical memory:		     %ld\n",a);
	a = sysconf(_SC_AVPHYS_PAGES);
	printf("number of currently available pages in the physical memory:  %ld\n",a);
	return 0;
}

/*
=======================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out
Max length of the arguments to the exec family of functions: 2097152
Max number of simultaneous process per user id: 	     62909
Number of clock ticks (jiffy) per second:		     100
Max number of open files by a process: 			     1024
Size of a page: 					     4096
total number of pages in the physical memory:		     4044943
number of currently available pages in the physical memory:  3171862

=======================================================================================================
*/
