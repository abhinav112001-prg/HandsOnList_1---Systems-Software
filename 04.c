/*
============================================================================================
Name: 04.c
Author: Abhinav Sharma
Description: Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 20th September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<time.h>
unsigned long long rdtsc() {
        unsigned long long dst;
        __asm__ __volatile__ ("rdtsc":"=A"(dst));
        return dst;
}

int main(void) {
	long long int start, end;
	start = rdtsc();
	for (int i=0; i<100; i++) {getppid();}
	end = rdtsc();
	printf("Start time=%lld\nEnd time=%lld\n",start,end);
	printf ("Difference = %llu\n", end-start);
	return 0;
}


/*
=======================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out
start time=443749704
End time=443932387
Difference = 182683
=======================================================================================================
*/
