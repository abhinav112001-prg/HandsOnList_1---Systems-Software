/*
============================================================================================
Name: 22.c
Author: Abhinav Sharma
Description: Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.
Date: 5th September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void) {
	char buf1[40] = "HELLOOO! How was your day?";
	char buf2[40] = "Good bye see you.";
	int fd = open("file22_01.txt", O_RDWR|O_CREAT|O_TRUNC, 0644);

	if(!fork()) {
		write(fd, buf1, sizeof(buf1));
	}
	else {
		write(fd, buf2, sizeof(buf2));
	}
}
/*
=================================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ cc 22.c
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ cat file22_01.txt
Good bye see you.HELLOOO! How was your day?
=================================================================================================================
*/
