/*
============================================================================================
Name: 10.c
Author: Abhinav Sharma
Description: Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 26th August 2025
============================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
void main(void) {

	char buf1[10]="qwertyasdf";
	char buf2[10]="987654310";
	int fd = open("File1001.txt", O_RDWR | O_CREAT | O_TRUNC);
	off_t offset;
	write(fd, buf1, sizeof(buf1));
	// use of lseek
	offset = lseek(fd, 10, SEEK_CUR);
	printf("lseek value: %ld\n", (long)offset);
	write(fd, buf2, sizeof(buf2));
	close(fd);
}
/*
=====================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out 
lseek value: 20
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ od -c File1001.txt 
0000000   q   w   e   r   t   y   a   s   d   f  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   9   8   7   6   5   4   3   1   0  \0
0000036

=====================================================================================================

*/
