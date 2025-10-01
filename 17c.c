/*
============================================================================================================
Name: 17b.c
Author: Abhinav Sharma
Description: Write a program to execute ls -l | wc.
c. use fcntl
Date: 29th September 2025
============================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(void) {
	int pipefd[2];
	pid_t pid;
	pipe(pipefd);
	pid = fork();
	if(pid == 0) { // for ls
		close(pipefd[0]);
		close(STDOUT_FILENO); // ensures fd 1 is free
		fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO);
		close(pipefd[1]);
		execlp("ls", "ls", "-l", NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else { // wc
		close(pipefd[1]);
		close(STDIN_FILENO); // ensures fd 0 is free
		fcntl(pipefd[0], F_DUPFD, STDIN_FILENO);
		close(pipefd[0]);
		execlp("wc", "wc", NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	return 0;
}
/*
============================================================================================================

abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ cc 17c.c
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out
     34     301    2306

============================================================================================================
*/
