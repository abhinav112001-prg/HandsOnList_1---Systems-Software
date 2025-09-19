#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/time.h>
unsigned long long rdtsc() {
	unsigned long long dst;
// what the hell?
	__asm__ __volatile__ ("rdtsc":"=A"(dst));
	return dst;
}

int main(void) {
long long int start, end;
start = rdtsc();
pid_t process = getpid();
end = rdtsc();
printf ("Difference = %llu\n", end-start);
return 0;
}
