/*
============================================================================================
Name: 06.c
Author: Abhinav Sharma
Description: Write a simple program to create three threads.
Date: 20th September 2025
============================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
void thread_func(void) { sleep(4); printf("Thread id is %lu\n", pthread_self()); }
void thread_func2(void) {
	sleep(10);
	printf("HELLO, Thread Id =  %lu\n", pthread_self());
}
int main () {
	pthread_t mythread;
	pthread_create (&mythread, NULL, (void *) thread_func, NULL);
	pthread_create (&mythread, NULL, (void *) thread_func2, NULL);
	pthread_create (&mythread, NULL, (void *) thread_func, NULL);
	// copy above to make multiple threads 
	pthread_join(mythread, NULL);
	exit(0);
}
/*
=======================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out

=======================================================================================================
*/
