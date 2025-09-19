/*
============================================================================================
Name: 01b.c
Author: Abhinav Sharma
Description: Create the following types of a files using (i) shell command (ii) system call
b. hard link (symlink system call)
Date: 7th September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void) {
	char filename[50] = "file0101.txt";
	int x = link(filename, "hard_link.txt");
	if (x!= -1) printf("Hard Link created!");
	return 0;
}
/*
=========================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
Hard Link created!
=========================================================================================================
*/
