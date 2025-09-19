/*
============================================================================================
Name: 30.c
Author: Abhinav Sharma
Description: Write a program to run a script at a specific time using a Daemon process.
Date: 7th September 2025
============================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

void daemonize() {
    pid_t pid;
    pid = fork();

    if (pid > 0) exit(EXIT_SUCCESS); // Parent exits
    if (setsid() < 0) exit(EXIT_FAILURE);

    pid = fork();
    if (pid > 0) exit(EXIT_SUCCESS);

    if (chdir("/") < 0) exit(EXIT_FAILURE);
    umask(0);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <HH> <MM> <path_to_script>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int target_hour = atoi(argv[1]);
    int target_min = atoi(argv[2]);
    const char *script_path = argv[3];

    if (target_hour < 0 || target_hour > 23 || target_min < 0 || target_min > 59) {
        fprintf(stderr, "Error: Invalid time format. Please use HH (0-23) and MM (0-59).\n");
        exit(EXIT_FAILURE);
    }

    printf("Scheduling '%s' to run at %02d:%02d.\n", script_path, target_hour, target_min);

    daemonize();

    while (1) {
        time_t now = time(NULL);
        struct tm *current_time = localtime(&now);

        if (current_time->tm_hour == target_hour && current_time->tm_min == target_min) {

            pid_t child_pid = fork();

            if (child_pid < 0) {
                sleep(60);
                continue;
            }

            if (child_pid == 0) {
                execl("/bin/sh", "sh", script_path, NULL);
                exit(EXIT_FAILURE);
            }

            exit(EXIT_SUCCESS);
        }

        sleep(60);
    }

    return EXIT_SUCCESS;
}
/*
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ cc 30.c -o daemon_sched
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./daemon_sched 22 43 /home/abhinav-sharma/Documents/HandsOnList_1Scheduling '/home/abhinav-sharma/Documents/HandsOnList_1' to run at 22:43.
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ps -ef | grep daemon_sched
abhinav+    3858    1596  0 22:42 ?        00:00:00 ./daemon_sched 22 43 /home/abhinav-sharma/Documents/HandsOnList_1
abhinav+    3876    2943  0 22:43 pts/0    00:00:00 grep --color=auto daemon_sched
*/
