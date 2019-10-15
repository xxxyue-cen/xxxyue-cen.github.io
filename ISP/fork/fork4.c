#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{

	pid_t pid;
	pid = fork();
	int ret;
	pid_t pid_c;
	if(pid > 0 )
	{
		while(1)
		{
			printf("pid %d\n",getpid());
			printf("wait\n");

			//		pid_c = wait(&ret);

			pid_c = waitpid(0,&ret,WNOHANG);
			printf("pid_c :%d,ret = %d\n",pid_c,ret);

			if(WIFEXITED(ret))
			{
				printf("程序正常退出\n");
			}

			break;
		}
		exit(2);
	}else if(pid == 0)
	{

		sleep(3);
		printf("pid %d\tppid:%d\n",getpid(),getppid());
		exit(1);

	}else
	{
		printf("fork");
	}
}


