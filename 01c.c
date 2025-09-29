/*
============================================================================================
Name: 01b.c
Author: Abhinav Sharma
Description: Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date: 21th September 2025
============================================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>
void handler(int signal) { printf("ITIMER_PROF expired!\n");}
int main(void) {
/*
struct itimerval {
	struct timeval it_interval; // Interval for periodic timer
	struct timeval it_value;    // Time until next expiration
};

struct timeval {
        time_t      tv_sec;         // seconds
        suseconds_t tv_usec;        // microseconds
};
*/
	struct itimerval timer;
	signal(SIGPROF, handler);

	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 0;
	timer.it_value.tv_sec = 10;
	timer.it_value.tv_usec = 0;
	setitimer(ITIMER_PROF, &timer, NULL);

	pause();
	return 0;
}

/*
=======================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_2$ ./a.out
Timer expired!

=======================================================================================================
*/
