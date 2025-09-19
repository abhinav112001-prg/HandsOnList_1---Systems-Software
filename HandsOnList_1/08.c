/*
============================================================================================
Name: 08.c
Author: Abhinav Sharma
Description: Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 7th September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main() {
	char filename[50];
	char buf[50];
	int fd;

	fd = open("file0801.txt",O_RDONLY|O_CREAT);

	while(read(fd, buf, 1) > 0) {
		if (buf[0]=='\n'){
			getchar();
		}
		else {
                	write(1, buf, 1);
                }
	}
	close(fd);
}
/*
=======================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
Operating systems are an essential part of any computer system.
An operating system acts as an intermediary between the user and hardware.
Some operating systems are designed to be convenient, others to be efficient, and others
some combination of the two.
========================================================================================================
*/
