#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int main()
{
	pid_t pid;
	pid  =fork();
	if(pid == 0)
	{	
		sleep(3);
		kill(getppid(),9);
		exit(1);
	}else if(pid > 0)
	{
		while(1)
		{
			printf(" main :%d\n",getpid());
			sleep(1);
		}
	}else
	{
		perror("fork");
	
	}
	return 0;
}

