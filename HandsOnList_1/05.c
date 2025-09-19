/*
===============================================================================================================
Name: 05.c
Author: Abhinav Sharma
Description: Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 17th August 2025
===============================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main() {
	int fd[5];
	char fname[20];
	for (int i = 0; i < 5; i++) {
		snprintf(fname, sizeof(fname), "file05%d.txt", i+1);
		fd[i] = open(fname, O_RDWR|O_CREAT, 0644);
		printf("File created: %s. File descriptor: %d\n", fname, fd[i]);
	}
	for(;;) {
		sleep(5);
	}
}
/*
=======================================================================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ cc 05.c
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out &
[1] 3245
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ File created: file051.txt. File descriptor: 3
File created: file052.txt. File descriptor: 4
File created: file053.txt. File descriptor: 5
File created: file054.txt. File descriptor: 6
File created: file055.txt. File descriptor: 7
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ls -l /proc/3245/fd
total 0
lrwx------ 1 abhinav-sharma abhinav-sharma 64 Sep  7 21:05 0 -> /dev/pts/0
lrwx------ 1 abhinav-sharma abhinav-sharma 64 Sep  7 21:05 1 -> /dev/pts/0
lrwx------ 1 abhinav-sharma abhinav-sharma 64 Sep  7 21:05 2 -> /dev/pts/0
lrwx------ 1 abhinav-sharma abhinav-sharma 64 Sep  7 21:05 3 -> /home/abhinav-sharma/Documents/HandsOnList_1/file051.txt
lrwx------ 1 abhinav-sharma abhinav-sharma 64 Sep  7 21:05 4 -> /home/abhinav-sharma/Documents/HandsOnList_1/file052.txt
lrwx------ 1 abhinav-sharma abhinav-sharma 64 Sep  7 21:05 5 -> /home/abhinav-sharma/Documents/HandsOnList_1/file053.txt
lrwx------ 1 abhinav-sharma abhinav-sharma 64 Sep  7 21:05 6 -> /home/abhinav-sharma/Documents/HandsOnList_1/file054.txt
=======================================================================================================================================================
*/
