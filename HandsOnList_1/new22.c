/*
============================================================================================
Name: 22.c
Description: Write a program, open a file, call fork, and then write to the file by both the child as well as the parent processes. Check output of the file.
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
	char output[100];
	read(fd, output, 100);
	printf("%s",output);
}
