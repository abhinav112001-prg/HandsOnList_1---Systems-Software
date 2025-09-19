/*
===================================================================================================================
Name: 17a.c
Author: Abhinav Sharma
Description:- Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit.
Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
Date: 31st August 2025
===================================================================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

struct ticket_db {
	int ticket_no;
};

void main()
{
	int fds;
	struct ticket_db db;
	db.ticket_no = 1000;
	fds = open("ticket_db",O_RDWR|O_CREAT,0644);

	write(fds, &db, sizeof(db));
	printf("Initialized ticket number: %d\n", db.ticket_no);
	close(fds);
}

//*
==================================================================================================================
bhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
Initialized ticket number: 1000

==================================================================================================================
*/
