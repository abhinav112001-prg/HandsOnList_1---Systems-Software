/*
=============================================================================================
Name: 01a.c
Author: Abhinav Sharma
Description: Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 7th September 2025
=============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void) {
	char filename[70] = "/home/abhinav-sharma/Documents/lsCommand.txt";
	int x= symlink(filename, "/home/abhinav-sharma/Desktop/ls_l_link.txt");
	if (x!= -1) printf("Soft Link created!");
	return 0;
}
/*
==================================================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ echo "HELLO WORLD" > file0101.txt
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
Soft Link created
==================================================================================================================================
*/
