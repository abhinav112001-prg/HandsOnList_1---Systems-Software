/*
============================================================================================
Name: 19d.c
Author: Abhinav Sharma
Description: Create a FIFO file by
d. mknod system call.
Date: 30th September 2025
============================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main(){
	int fifo = mknod("FifoNew",S_IFIFO,0);
	if (fifo != -1) printf("FifoNew created.\n");
	else {
		perror("mknod");
		exit(1);
	}
	return 0;
}
/*
============================================================================================

============================================================================================
*/
