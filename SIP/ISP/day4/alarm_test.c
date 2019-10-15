#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle(int sig)
{
	printf("get signal %d\n",sig);
	
}
int main()
{


	signal(2,SIG_IGN);
	signal(SIGTSTP,SIG_IGN);

	signal(14,handle);
	
	while(1)
	{
		alarm(2);
		printf("send alarm\n");
		sleep(5);
	}

}
