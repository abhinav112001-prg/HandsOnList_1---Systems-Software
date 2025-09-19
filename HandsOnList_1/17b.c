/*
===================================================================================================================
Name: 17b.c
Author: Abhinav Sharma
Description:- Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit.
Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print the new ticket number then close the file.
Date: 31st August 2025
===================================================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

struct ticket_db {
	int ticket_no;
};

void main()
{
	int fd;
	struct ticket_db db;
	struct flock l;

	fd = open("ticket_db", O_RDWR);

	read(fd, &db, sizeof(db));

	l.l_type = F_WRLCK;
	l.l_whence = SEEK_SET;
	l.l_start = 0;
	l.l_len = 0;
	l.l_pid = getpid();
	printf("Before entering critical section\n");
	fcntl(fd, F_SETLKW, &l);
	printf("Critical Section\n");

	lseek(fd, 0, SEEK_SET);
	read(fd, &db, sizeof(db));

	printf("Present ticket number: %d\n", db.ticket_no);
	db.ticket_no++;
	printf("New ticket number: %d\n", db.ticket_no);

	lseek(fd, 0, SEEK_SET);
	write(fd, &db, sizeof(db));

	printf("Enter any key to proceed and unlock..\n");
	getchar();

	write(fd, &db, sizeof(db));

	l.l_type = F_UNLCK;
	printf("Unlocking file\n");
	fcntl(fd, F_SETLK, &l);
	close(fd);
}

/*
==================================================================================================================

(Terminal 1):
Before entering critical section
Lock acquired. Inside Critical Section...
Current ticket number: 1001
New ticket number: 1002
Enter any key to proceed and unlock..

(Terminal 2):
Before entering critical section

==================================================================================================================
*/
