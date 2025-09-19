/*
============================================================================================
Name: 11.c
Author: Abhinav Sharma
Description: Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 5th September 2025
============================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(void) {
	int fd1 = open("File1101.txt",O_RDWR|O_CREAT|O_TRUNC,0644);
	printf("Original FD value = %d\n",fd1);
	write(fd1, "Original", 9);
	int fd2,fd3,fd4;
	fd2 = dup(fd1);
	fd3 = dup2(fd1,10); // target fd number is 10
	fd4 = fcntl(fd1, F_DUPFD, 0);


	char s2[50], s3[50], s4[50];
	sprintf(s2, "Original and dup fd = %d, %d\n",fd1,fd2);
        sprintf(s3, "Original and dup2 fd = %d, %d\n",fd1,fd3);
        sprintf(s4, "Original and fcntl fd = %d, %d\n",fd1,fd4);
	printf("%s\n%s\n%s\n",s2,s3,s4);
	write(fd2, s2, sizeof(s2));
	write(fd3, s3, sizeof(s3));
	write(fd4, s4, sizeof(s4));
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);

}

/*
=====================================================================================================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ cc 11.c
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
Original FD value = 3
Original and dup fd = 3, 4

Original and dup2 fd = 3, 10

Original and fcntl fd = 3, 5

abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ open File1101.txt
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ cat File1101.txt
OriginalOriginal and dup fd = 3, 4
�Original and dup2 fd = 3, 10
Original and fcntl fd = 3, 5
Px�abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$
=====================================================================================================================================================================================
*/
