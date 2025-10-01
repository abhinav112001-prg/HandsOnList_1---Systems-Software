/*
============================================================================================================
Name: 17b.c
Author: Abhinav Sharma
Description: Write a program to execute ls -l | wc.
b. use dup2
Date: 29th September 2025
============================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(void) {
	int pipefd[2];
	pid_t pid;
	pipe(pipefd);
	pid = fork();
	if(pid == 0) { // for ls
		close(pipefd[0]);
		dup2(pipefd[1],STDOUT_FILENO);
		close(pipefd[1]);
		execlp("ls", "ls", "-l", NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else { // wc
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		execlp("wc", "wc", NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	return 0;
}
/*
============================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ cc 17b.c
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out 
     33     292    2237

============================================================================================================
*/
