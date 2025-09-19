/*
============================================================================================
Name: 04.c
Author: Abhinav Sharma
Description: Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 14th August 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main() {
	int fd = open("file0401.txt",O_RDWR|O_TRUNC|O_EXCL,0644);
	write(fd, "Hello", 6);
	printf("%d\n",fd);
}
/*
==================================================================================================================

abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ touch file0401.txt
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ cc 04.c 
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
3
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ cat file0401.txt 
Hello
=================================================================================================================

*/
