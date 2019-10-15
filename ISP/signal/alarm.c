#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle(int sig)
{
	printf("get signal %d\n",sig);
	exit(1);
}
int main()
{

	signal(14,handle);
//	while(1)
//
	{
		alarm(2);
		printf("send alarm\n");

		sleep(2);
	}

}
