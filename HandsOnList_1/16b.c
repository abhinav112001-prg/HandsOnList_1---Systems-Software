/*
============================================================================================
Name: 16b.c
Author: Abhinav Sharma
Description:  Write a program to perform mandatory locking.
b. Implement write lock
Date: 6th September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd;
	//opening file, creating if doesnt exist
	fd = open("db", O_RDWR | O_CREAT | O_TRUNC, 0644);
	// flock F Lock
	struct flock l;
	l.l_type = F_WRLCK; //read lock
	l.l_whence = SEEK_SET;
	l.l_start = 0;
	l.l_len = 0;
	l.l_pid = getpid();
	printf("Before CRITICAL SECTION\n");
	// waiting lock for fd
	fcntl(fd, F_SETLKW, &l);
	printf("CRITICAL SECTION\n");
	printf("Enter to unlock\n");
	getchar();
	// after C.S. unlock l
	printf("Unlocked!\n");
	l.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &l);
	printf("End of CRITICAL SECTION.\n");
	close(fd);
	return 0;

}
/*
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./write_lock_16 
Before CRITICAL SECTION

CRITICAL SECTION
Enter to unlock
Unlocked!
End of CRITICAL SECTION.

*/
