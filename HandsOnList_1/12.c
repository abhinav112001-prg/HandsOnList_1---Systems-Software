/*
============================================================================================
Name: 12.c
Author: Abhinav Sharma
Description: Write a program to find out the opening mode of a file. Use fcntl.
Date: 31st August 2025
============================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(void) {
	char filename[80];
	printf("enter filename: \n");
	scanf("%s", filename);
	int fd;
	fd = open(filename, O_RDWR|O_CREAT|O_APPEND, 0644);

	int flags = fcntl(fd, F_GETFL);
	printf("%d\n", flags);

	int accessMode = flags & O_ACCMODE;
	printf("File access mode: ");
	switch(accessMode) {
		case O_RDONLY:
			printf("READONLY\n");
			break;
		case O_WRONLY:
			printf("READONLY\n");
			break;
		case O_RDWR:
			printf("READONLY\n");
			break;
		default:
			printf("READONLY\n");
			break;
	}
	close(fd);
	return EXIT_SUCCESS;
}
/*
===================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
enter filename: 
File1201.txt
33794
File access mode: READONLY
===================================================================================================
*/
