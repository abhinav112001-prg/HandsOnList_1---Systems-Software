/*
============================================================================================
Name: 13.c
Author: Abhinav Sharma
Description: Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 31st August 2025
============================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/select.h>
#include<sys/time.h>
int main(void) {

	fd_set readfds; // file descriptor set
	struct timeval tv;
	tv.tv_sec = 10;
	tv.tv_usec = 0;
	FD_ZERO(&readfds); // clear the fd set
	FD_SET(0, &readfds); // add STDIN fd in the set
	printf("Waiting 10 seconds.\n");
	fflush(stdout);

	int ret;
	ret= select(1, &readfds, NULL, NULL, &tv);
	if(ret == -1){
		perror("select()");
		return EXIT_FAILURE;
	}
	else if(ret) {
		if(FD_ISSET(0, &readfds))
			printf("Data availble now: %d!\n",ret);
	}
	else
		printf("No data received within 10 seconds.\n");
	return EXIT_SUCCESS;
}
/*
=======================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out 
Waiting 10 seconds.
hi
Data availble now: 1!
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out 
Waiting 10 seconds.
No data received within 10 seconds.
=======================================================================================================
*/
