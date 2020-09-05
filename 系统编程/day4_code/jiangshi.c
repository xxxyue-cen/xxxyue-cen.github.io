#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	int pid = fork();
	printf("pid_fork = %d\n",pid);
	if(pid == 0)
	{
//子进程	
		printf("child\n");
		printf("pid = %d\n",getpid());
		printf("ppid = %d\n",getppid());
	}
	else if(pid >0)
	{
//父进程
		printf("father\n");
		while(1)
		{
			sleep(2);
			printf("pid = %d\n",getpid());
		  printf("ppid = %d\n",getppid());
		}	
	}
}
