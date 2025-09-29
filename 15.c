#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void) {
	int fds[2];
	char buffer[50];
	pipe(fds);
	if(!fork()) {
		close(fds[0]);
		write(fds[1], "GoodBye", 8);
	}

	else {
		close(fds[1]);
		//s_size x= read
	}
	return EXIT_SUCCESS;

}
