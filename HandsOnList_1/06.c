/*
============================================================================================
Name: 06.c
Author: Abhinav Sharma
Description: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 14th August 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main(){
	int rbuffer[20];
	ssize_t r = read(0, rbuffer, sizeof(rbuffer));
	printf("Bytes read = %zd.\n", r);
	write(1, rbuffer, r);

}
/*
======================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
hello there!
Bytes read = 13.
hello there!
=====================================================================================================
*/
