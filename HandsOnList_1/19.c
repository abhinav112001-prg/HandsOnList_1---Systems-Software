/*
============================================================================================
Name: 19.c
Author: Abhinav Sharma
Description: Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 3rd September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<time.h>
int main(void) {
	clock_t start,end;
	start = clock();
	int id = getpid();
	end = clock();
	double totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("%f seconds", totalTime);
}
//*
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
0.000004 seconds
*//
