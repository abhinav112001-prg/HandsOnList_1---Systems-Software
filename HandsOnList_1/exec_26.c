#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]) {
	printf("Hello %s!\nHow are you?\n",argv[1]);
	return 0;
}

/*
$ nano exec_26.c
$ cc exec_26.c -o exec_26
$ ./exec_26 myname
*/
