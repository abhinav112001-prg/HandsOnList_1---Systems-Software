#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void) {
	int fds[2];
	int buf[100];
	pipe(fds);

	write(fds[1], "hello", 6);
	close(fds[1]);

	ssize_t b = read(fds[0],buf,sizeof(buf));
	close(fds[0]);
	printf("Read no of bytes: %zd\n",b);
	return EXIT_SUCCESS;

}
