/*
============================================================================================
Name: 27e.c
Author: Abhinav Sharma
Description: Write a program to execute ls -Rl by the following system calls
e. execvp
Date: 7th September 2025
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
    execvp("ls", args);
    perror("execvp failed");
    exit(1);
}


/*
===================================================================================================================
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out
.:
total 300
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1108 Sep  7 23:29 01a.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma   926 Sep  7 23:31 01b.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  2767 Sep  7 23:36 01c.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  8060 Sep  7 20:47 02.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1068 Sep  7 20:51 03.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1201 Sep  7 20:59 04.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  2463 Sep  7 21:06 05.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma   914 Sep  7 21:08 06.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma   954 Sep  7 21:27 07.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1297 Sep  7 21:29 08.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1572 Sep  7 21:30 09.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1504 Sep  7 21:34 10.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  2298 Sep  7 21:12 11.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1319 Sep  7 21:37 12.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1616 Sep  7 21:40 13.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  2299 Sep  7 21:10 14.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  4298 Sep  7 21:41 15.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1330 Sep  7 21:44 16a.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1180 Sep  7 21:14 16b.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1315 Sep  7 23:12 17a.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1983 Sep  7 23:15 17b.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  3957 Sep  7 23:00 18.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma   730 Sep  7 21:45 19.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1537 Sep  7 21:47 20.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1035 Sep  7 21:50 21.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1324 Sep  7 21:53 22.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1748 Sep  7 22:01 23.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1495 Sep  7 22:10 24.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  2142 Sep  7 23:06 25.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma   898 Sep  7 21:20 26.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1152 Sep  7 23:41 27a.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1275 Sep  7 23:41 27b.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1444 Sep  7 23:41 27c.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1558 Sep  7 23:41 27d.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1687 Sep  7 23:41 27e.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1539 Sep  7 22:16 28.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  1788 Sep  7 22:21 29.c
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma  2347 Sep  7 22:46 30.c
-rwxrwxr-x 1 abhinav-sharma abhinav-sharma 16040 Sep  7 23:42 a.out
-rwxrwxr-x 1 abhinav-sharma abhinav-sharma 16552 Sep  7 22:41 daemon_sched
-rw-r--r-- 1 abhinav-sharma abhinav-sharma     0 Sep  7 17:36 db
drwxrwxr-x 2 abhinav-sharma abhinav-sharma  4096 Sep  7 15:09 directory_14
-rwxrwxr-x 1 abhinav-sharma abhinav-sharma 15968 Sep  7 15:37 exec_26
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma   200 Sep  7 15:37 exec_26.c
p--------- 1 abhinav-sharma abhinav-sharma     0 Sep  7 23:35 fifo0101
-rwxr--r-- 1 abhinav-sharma abhinav-sharma     0 Sep  7 20:49 fiileY.txt
-rw-rw-r-- 2 abhinav-sharma abhinav-sharma    12 Sep  7 23:27 file0101.txt
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma     6 Sep  7 20:58 file0401.txt
-rw-r--r-- 1 abhinav-sharma abhinav-sharma     0 Sep  7 21:00 file051.txt
-rw-r--r-- 1 abhinav-sharma abhinav-sharma     0 Sep  7 21:00 file052.txt
-rw-r--r-- 1 abhinav-sharma abhinav-sharma     0 Sep  7 21:00 file053.txt
-rw-r--r-- 1 abhinav-sharma abhinav-sharma     0 Sep  7 21:00 file054.txt
-rw-r--r-- 1 abhinav-sharma abhinav-sharma     0 Sep  7 21:00 file055.txt
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma    30 Aug 24 15:13 File0701.txt
-rw--w---- 1 abhinav-sharma abhinav-sharma   400 Sep  7 21:27 File0702.txt
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma   257 Sep  7 11:59 file0801.txt
-rwS-wx--T 1 abhinav-sharma abhinav-sharma     0 Aug 24 15:53 File0901
-rw-rwx--- 1 abhinav-sharma abhinav-sharma    30 Sep  7 21:33 File1001.txt
-rw-r--r-- 1 abhinav-sharma abhinav-sharma   159 Sep  7 14:11 File1101.txt
-rw-r--r-- 1 abhinav-sharma abhinav-sharma     0 Aug 31 13:13 File1201.txt
-rwxrws--- 1 abhinav-sharma abhinav-sharma     0 Aug 31 11:56 File1301.txt
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma     0 Sep  7 15:09 File1401.txt
-rw-r--r-- 1 abhinav-sharma abhinav-sharma    80 Sep  5 19:33 file22_01.txt
-rwxr--r-- 1 abhinav-sharma abhinav-sharma     0 Sep  7 20:49 fileX.txt
-rwxr--r-- 1 abhinav-sharma abhinav-sharma     0 Sep  7 20:49 fileZ.txt
-rw-rw-r-- 2 abhinav-sharma abhinav-sharma    12 Sep  7 23:27 hard_link.txt
-rwxrwxr-x 1 abhinav-sharma abhinav-sharma 16224 Sep  7 17:36 read_lock_16
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma    12 Sep  7 22:58 records.dat
lrwxrwxrwx 1 abhinav-sharma abhinav-sharma    12 Sep  7 23:25 soft_link.txt -> file0101.txt
-rw-rw-r-- 1 abhinav-sharma abhinav-sharma   165 Sep  7 22:39 TestScript.sh
-rw-r--r-- 1 abhinav-sharma abhinav-sharma     8 Sep  7 23:15 ticket_db
-rwxrwxr-x 1 abhinav-sharma abhinav-sharma 16224 Sep  7 17:35 write_lock_16

./directory_14:
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$

===================================================================================================================
*/
