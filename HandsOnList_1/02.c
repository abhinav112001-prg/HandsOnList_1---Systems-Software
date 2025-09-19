/*
================================================================================================================
Name: 02.c
Author: Abhinav Sharma
Description: Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 13th August 2025
================================================================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main() {
	while(1);
	return 0;
}

/*
=============================================================================================================================================

abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ ./a.out &
[1] 4720
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:~/Documents/HandsOnList_1$ cd /
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:/$ cd proc
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:/proc$ ls
1     117   134   159   1758  19    2031  234   28    3298  40    4720  610  77   88    asound         kcore         softirqs
10    1175  135   16    176   1912  2037  235   2832  33    41    4745  611  786  882   bootconfig     keys          stat
100   118   1351  160   1760  1913  2054  2350  2895  331   4160  4808  612  788  883   buddyinfo      key-users     swaps
1008  1180  136   1605  177   1919  2064  2357  29    34    4176  49    613  789  885   bus            kmsg          sys
101   1186  137   1618  1770  1936  2069  236   290   3404  42    5     62   79   89    cgroups        kpagecgroup   sysrq-trigger
102   119   138   1619  1776  1939  208   237   291   3409  4264  50    63   8    894   cmdline        kpagecount    sysvipc
103   12    139   162   1779  1963  2089  2370  292   3423  43    500   64   80   900   consoles       kpageflags    thread-self
104   120   14    1625  178   1978  2090  238   293   3433  4303  51    65   800  91    cpuinfo        loadavg       timer_list
105   121   140   1628  179   1994  2091  239   294   3473  4315  52    66   808  92    crypto         locks         tty
106   122   141   1629  180   1995  2093  24    295   35    4353  53    664  81   93    devices        mdstat        uptime
107   1227  142   163   1806  1998  21    240   3     3540  4393  536   666  810  94    diskstats      meminfo       version
109   123   143   1641  1807  1999  210   2401  30    3565  44    55    667  82   95    dma            misc          version_signature
11    124   144   1642  181   2     2172  241   3036  362   4490  56    668  825  952   driver         modules       vmallocinfo
110   125   147   1667  1814  20    2189  242   3063  3665  45    569   669  83   96    dynamic_debug  mounts        vmstat
111   126   149   1675  182   2002  22    2486  3077  37    4515  57    67   835  967   execdomains    mtrr          zoneinfo
112   127   15    1685  183   2007  2206  25    31    3743  453   58    68   84   97    fb             net
113   128   150   169   1862  2012  2227  2536  317   38    4540  582   69   840  970   filesystems    pagetypeinfo
115   129   151   17    1870  2014  2237  254   318   3831  4550  586   70   848  972   fs             partitions
1156  13    153   1703  1879  2016  2257  26    32    3836  4584  59    71   85   974   interrupts     pressure
1157  1309  154   1707  1885  2022  2276  2620  3200  39    46    6     73   854  98    iomem          schedstat
116   131   155   171   1892  2024  23    268   3209  3955  4602  608   74   86   99    ioports        scsi
1160  132   156   172   1893  2025  232   27    3216  396   4603  609   75   863  990   irq            self
1162  133   157   1757  1899  2026  233   271   322   4     47    61    76   87   acpi  kallsyms       slabinfo
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:/proc$ cd 4720
abhinav-sharma@abhinav-sharma-ASUS-TUF-Gaming-A15-FA506NCR-FA566NCR:/proc/4720$ ls -l
total 0
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 arch_status
dr-xr-xr-x  2 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 attr
-rw-r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 autogroup
-r--------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 auxv
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 cgroup
--w-------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 clear_refs
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 cmdline
-rw-r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 comm
-rw-r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 coredump_filter
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 cpu_resctrl_groups
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 cpuset
lrwxrwxrwx  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 cwd -> /home/abhinav-sharma/Documents/HandsOnList_1
-r--------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 environ
lrwxrwxrwx  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 exe -> /home/abhinav-sharma/Documents/HandsOnList_1/a.out
dr-x------  2 abhinav-sharma abhinav-sharma 3 Sep  7 20:43 fd
dr-xr-xr-x  2 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 fdinfo
-rw-r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 gid_map
-r--------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 io
-r--------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 ksm_merging_pages
-r--------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 ksm_stat
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 limits
-rw-r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 loginuid
dr-x------  2 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 map_files
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 maps
-rw-------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 mem
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 mountinfo
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 mounts
-r--------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 mountstats
dr-xr-xr-x 59 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 net
dr-x--x--x  2 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 ns
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 numa_maps
-rw-r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 oom_adj
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 oom_score
-rw-r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 oom_score_adj
-r--------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 pagemap
-r--------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 patch_state
-r--------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 personality
-rw-r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 projid_map
lrwxrwxrwx  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 root -> /
-rw-r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 sched
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 schedstat
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 sessionid
-rw-r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 setgroups
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 smaps
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 smaps_rollup
-r--------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 stack
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 stat
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 statm
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 status
-r--------  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 syscall
dr-xr-xr-x  3 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 task
-rw-r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 timens_offsets
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 timers
-rw-rw-rw-  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 timerslack_ns
-rw-r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 uid_map
-r--r--r--  1 abhinav-sharma abhinav-sharma 0 Sep  7 20:43 wchan

=============================================================================================================================================
*/
