/*
============================================================================================================
Name: 16.c
Author: Abhinav Sharma
Description: Write a program to send and receive data from parent to child vice versa.
Use two way communication.
Date: 29th September 2025
============================================================================================================
*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main(void) {
	int pipe1[2];
	int pipe2[2];
	char buf[100];
	//creating two pipes
	pipe(pipe1);pipe(pipe2);
	pid_t pid = fork();
	if(pid>0) { // parent
		printf("Parent process.\n");
		close(pipe1[0]); close(pipe2[1]);
		char* data1 = "Hello Im Parent";
		write(pipe1[1], data1, strlen(data1)+1);
		read(pipe2[0], buf, sizeof(buf));
		close(pipe1[1]); close(pipe2[0]);
		printf("Data received from parent:\n%s\n",buf);
	}
	else if(pid==0) { // child
		printf("Child process.\n");
		close(pipe1[1]); close(pipe2[0]);
		char* data2 = "Hello Im Child";
		write(pipe2[1], data2, strlen(data2)+1);
		read(pipe1[0], buf, sizeof(buf));
		close(pipe1[0]); close(pipe2[1]);
		printf("Data received from parent:\n%s\n",buf);
	}
	return EXIT_SUCCESS;
}
/*
============================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out
Parent process.
Child process.
Data received from parent:
Hello Im Parent
Data received from parent:
Hello Im Child

============================================================================================================
*/