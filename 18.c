/*
============================================================================================================
Name: 18.c
Author: Abhinav Sharma
Description: Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc -l. Use only dup2.
Date: 30th September 2025
============================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(void) {
	int pipe1[2], pipe2[2];
	pid_t pid1,pid2,pid3;
	pipe(pipe1);
	pipe(pipe2);
	pid1 = fork();
	if(pid1 == 0) {
		dup2(pipe1[1], STDOUT_FILENO);
		close(pipe1[0]); close(pipe1[1]);
		close(pipe2[0]); close(pipe2[1]);
		execlp("ls", "ls", "-l", NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	pid2 = fork();
	if(pid2 == 0) {
		dup2(pipe1[0], STDIN_FILENO);
		dup2(pipe2[1], STDOUT_FILENO);
		close(pipe1[0]); close(pipe1[1]);
                close(pipe2[0]); close(pipe2[1]);
		execlp("grep", "grep", "^d", NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	pid3 = fork();
        if(pid3 == 0) {
                dup2(pipe2[0], STDIN_FILENO);
                close(pipe1[0]); close(pipe1[1]);
                close(pipe2[0]); close(pipe2[1]);
                execlp("wc", "wc", "-l", NULL);
                perror("execlp");
                exit(EXIT_FAILURE);
        }
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
	waitpid(pid1,NULL,0);
	waitpid(pid2,NULL,0);
	waitpid(pid3,NULL,0);
	return 0;
}
/*
============================================================================================================
cc 18.c
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out
4
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ls -l | grep ^d
drwxrwxr-x 2 abhinav-sharma abhinav-sharma   4096 Sep 30 16:35 dir10021
drwxrwxr-x 2 abhinav-sharma abhinav-sharma   4096 Sep 30 16:35 dir101
drwxrwxr-x 2 abhinav-sharma abhinav-sharma   4096 Sep 30 16:35 dir102
drwxrwxr-x 2 abhinav-sharma abhinav-sharma   4096 Sep 30 16:35 dirffff101
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ls -l | grep ^d | wc -l
4

============================================================================================================
*/
