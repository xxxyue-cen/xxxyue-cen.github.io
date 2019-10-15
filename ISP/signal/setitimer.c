
#if 0

struct itimerval {
	struct timeval it_interval; /* Interval for periodic timer */
	struct timeval it_value;    /* Time until next expiration */
};

struct timeval {
	time_t      tv_sec;         /* seconds */
	suseconds_t tv_usec;        /* microseconds */
};


ITIMER_REAL    decrements in real time, and delivers SIGALRM upon expiration.

ITIMER_VIRTUAL decrements only when the process is executing, and delivers SIGVTALRM upon expiration.

ITIMER_PROF    decrements both when the process executes and when the system is executing on behalf of the
process.  Coupled with ITIMER_VIRTUAL, this timer is usually used to profile the time spent
by the application in user and kernel space.  SIGPROF is delivered upon expiration.



#endif

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
void handle()
{
	printf("get setitimer\n");
}

int main()
{
	signal(14,handle);
	struct itimerval it;
	//alarm(second)
	// 定时器的时间
	it.it_interval.tv_sec  = 5;
	it.it_interval.tv_usec = 0;
	//以后每次使用的时间
	it.it_value.tv_sec = 3;
	it.it_value.tv_usec = 0;

	setitimer(ITIMER_REAL,&it,0); 
	sleep(20);


	return 0;
}




