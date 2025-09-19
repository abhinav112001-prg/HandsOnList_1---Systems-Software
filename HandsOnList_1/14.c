/*
============================================================================================
Name: 14.c
Author: Abhinav Sharma
Description: Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 7th September 2025
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char *argv[]) {

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	char *filepath = argv[1];
	struct stat file_stat;
	lstat(filepath, &file_stat);
	printf("File type for '%s': ", filepath);

	mode_t mode = file_stat.st_mode;
	switch (mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
	}

    return EXIT_SUCCESS;
}
/*
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
Usage: ./a.out <file_path>
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out directory_14
File type for 'directory_14': directory
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out fifo_14
File type for 'fifo_14': FIFO/pipe
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out 29.c
File type for '29.c': regular file
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out File1401.txt
File type for 'File1401.txt': regular file
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out /dev/tty8
File type for '/dev/tty8': character device

*/
