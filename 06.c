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
void thread_func(void) {
	printf("Hi I am Thread #1.\n");
}
void thread_func2(void) {
	printf("HELLO, this is Thread #2");
}
void thread_func3() {
	int i;
	for(i=0;i<10;i++)
		printf("Bye.");
	printf("\n(thread#3 here!)");
}
int main () {
	pthread_t t1, t2, t3;
	pthread_create (&t1, NULL, (void *) thread_func, NULL);
	pthread_create (&t2, NULL, (void *) thread_func2, NULL);
	pthread_create (&t3, NULL, (void *) thread_func3, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	exit(0);
}
/*
================================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ cc 06.c -lpthread
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out
Hi I am Thread #1.
HELLO, this is Thread #2Bye.Bye.Bye.Bye.Bye.Bye.Bye.Bye.Bye.Bye.
(thread#3 here!)
================================================================================================================
*/
