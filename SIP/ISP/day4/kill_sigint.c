#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


void handle(int sig)
{
	switch(sig)
	{
		case SIGINT: printf("SIGINT\n");
					 break;
		case SIGTSTP: printf("SIGTSTP\n");
					  break;
	}	
	exit(1);
}


int main()
{

	signal(SIGINT,handle);
	signal(SIGTSTP,handle);
	pid_t pid;
	pid  =fork();
	if(pid == 0)
	{	
		sleep(3);
		//kill(getppid(),SIGINT);
//		kill(getppid(),SIGTSTP);
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

