/*
============================================================================================
Name: 01c.c
Author: Abhinav Sharma
Description: Create the following types of a files using (i) shell command (ii) system call
b. FIFO (FIFO system call)
Date: 7th September 2025
============================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
// int mknod(const char *pathname, mode_t mode, dev_t dev);
int main(void) {
	char filename[50] = "fifo0101";
	if (mknod(filename, S_IFIFO, 0) != -1) {
		printf("FIFO created!");
	}
	return 0;
}
/*
============================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ls
01a.c  05.c  11.c   16b.c  21.c  28.c          directory_14  file051.txt   File0702.txt  File1301.txt   read_lock_16
01b.c  06.c  12.c   17a.c  22.c  29.c          exec_26       file052.txt   file0801.txt  File1401.txt   records.dat
01c.c  07.c  13.c   17b.c  23.c  30.c          exec_26.c     file053.txt   File0901      file22_01.txt  soft_link.txt
02.c   08.c  14.c   18.c   24.c  a.out         fiileY.txt    file054.txt   File1001.txt  fileX.txt      TestScript.sh
03.c   09.c  15.c   19.c   25.c  daemon_sched  file0101.txt  file055.txt   File1101.txt  fileZ.txt      ticket_db
04.c   10.c  16a.c  20.c   26.c  db            file0401.txt  File0701.txt  File1201.txt  hard_link.txt  write_lock_16
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ cc 01c.c 
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out 
FIFO created!abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ls
01a.c  05.c  11.c   16b.c  21.c  28.c          directory_14  file0401.txt  File0701.txt  File1201.txt   hard_link.txt  write_lock_16
01b.c  06.c  12.c   17a.c  22.c  29.c          exec_26       file051.txt   File0702.txt  File1301.txt   read_lock_16
01c.c  07.c  13.c   17b.c  23.c  30.c          exec_26.c     file052.txt   file0801.txt  File1401.txt   records.dat
02.c   08.c  14.c   18.c   24.c  a.out         fifo0101      file053.txt   File0901      file22_01.txt  soft_link.txt
03.c   09.c  15.c   19.c   25.c  daemon_sched  fiileY.txt    file054.txt   File1001.txt  fileX.txt      TestScript.sh
04.c   10.c  16a.c  20.c   26.c  db            file0101.txt  file055.txt   File1101.txt  fileZ.txt      ticket_db
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ 

============================================================================================
*/
