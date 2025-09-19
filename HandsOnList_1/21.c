/*
============================================================================================
Name: 21.c
Author: Abhinav Sharma
Description: Write a program, call fork and print the parent and child process id
Date: 3rd September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main(void) {
	int a,b;
	if(!fork()) { //parent
		printf("FOR PARENT!\n");
		printf("Parent: %d\n",getppid());
		printf("Child: %d\n",getpid());
	}
	else { //child
		printf("FOR CHILD!\n");
		printf("Child: %d\n",getpid());
		printf("Parent: %d\n",getppid());
	}
}
//*
=========================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out 
FOR CHILD!
Child: 5760
Parent: 2981
FOR PARENT!
Parent: 5760
Child: 5761
=========================================================================================================
*//
