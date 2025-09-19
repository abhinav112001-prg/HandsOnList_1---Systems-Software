/*
============================================================================================
Name: 07.c
Author: Abhinav Sharma
Description: Write a program to take input
Date: 24th August 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main() {

	int fd1, fd2;
	fd1 = open("File0701.txt", O_RDWR);
	int buf[100];
	read(fd1, buf, sizeof(buf));
	fd2 = open("File0702.txt", O_RDWR | O_CREAT);
	write(fd2, buf, sizeof(buf));
	printf("File copied into file descriptor => %d\n",fd2);
}
/*
=======================================================================================================

abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
File copied into file descriptor => 4
=======================================================================================================
*/
