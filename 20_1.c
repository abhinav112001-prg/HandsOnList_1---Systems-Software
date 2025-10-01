/*
============================================================================================
Name: 20_1.c
Author: Abhinav Sharma
Description: Wr
Date: 30th September 2025
============================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<errno.h>
int main(){
	if (mkfifo("FifoNew", 0666) == -1) {
		perror("mkfifo");
		if (errno != EEXIST) {
			exit(EXIT_FAILURE);
		}// Ignore error if FIFO already exists
	}
	int fifofd;
	char buffer[100];
	fifofd = open("FifoNew", O_WRONLY);
	while(1) {
		printf("Enter message (or press q to quit):");

		fgets(buffer, sizeof(buffer), stdin);
       		// Remove newline from fgets
        	buffer[strcspn(buffer, "\n")] = '\0';

		write(fifofd, buffer, strlen(buffer)+1);
		if (strcmp(buffer,"q") == 0) break;
	}
	close(fifofd);
	unlink("FifoNew");
	return 0;
}
/*
============================================================================================

============================================================================================
*/
