/*
============================================================================================
Name: 01.c
Author: Abhinav Sharma
Description: Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
Date: 13th August 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main() {
	int fd = creat("fileX.txt", 0744);
	int fd2 = creat("fiileY.txt", 0744);
	int fd3 = creat("fileZ.txt", 0744);
	printf("1st fd value is = %d\n",fd);
	printf("2nd fd value is = %d\n",fd2);
	printf("3rd fd value is = %d\n",fd3);

	return 0;
}
/*
=======================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
1st fd value is = 3
2nd fd value is = 4
3rd fd value is = 5
=======================================================================================================
*/
