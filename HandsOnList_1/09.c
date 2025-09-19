/*
============================================================================================
Name: 09.c
Author: Abhinav Sharma
Description: Write a program to take input
Date: 26th August 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
void main(void){
	int fd;
	struct stat filestat;
	fd = open("File0901", O_RDONLY|O_CREAT);
	fstat(fd, &filestat); //system call to get details about file
	printf("inode = %ld\n",filestat.st_ino);			// 1
	printf("no. of hard links = %ld\n",filestat.st_nlink);		// 2
	printf("uid = %d\n",filestat.st_uid);				// 3
	printf("gid = %d\n",filestat.st_gid);				// 4
	printf("File size = %ld\n",filestat.st_size);			// 5
	printf("Block size = %ld\n",filestat.st_blksize);		// 6
	printf("No. of blocks = %ld\n",filestat.st_blocks);		// 7
	printf("Last Access: %ld\n", filestat.st_atime);		// 8
	printf("Last Modification: %ld\n", filestat.st_mtime);		// 9
	printf("Last Status Change: %ld\n", filestat.st_ctime);		//10
}
/*
===========================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out 
inode = 3956817
no. of hard links = 1
uid = 1000
gid = 1000
File size = 0
Block size = 4096
No. of blocks = 0
Last Access: 1757236369
Last Modification: 1756031014
Last Status Change: 1756031014
===========================================================================================

*/
