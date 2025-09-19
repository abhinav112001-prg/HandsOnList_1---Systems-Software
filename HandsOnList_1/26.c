/*
============================================================================================
Name: 26.c
Author: Abhinav Sharma
Description: Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 6th September 2025
============================================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void) {
	execl("./exec_26", "exec_26", "MyName", NULL);
	return 0;
}
/*
===========================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out 
Hello MyName!
How are you?
===========================================================================================
*/
