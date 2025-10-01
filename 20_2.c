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

int main(){
	int fifofd = open("FifoNew", O_RDONLY);
	char buffer[100];
	while(1) {
		if(read(fifofd, buffer, sizeof(buffer) > 0)) {
			if(strcmp(buffer, "q") == 0) {
				break;
			}
                	printf("Received: %s\n", buffer);
		}
	}
	close(fifofd);
	return 0;
}
/*
============================================================================================

============================================================================================
*/
