#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{

	pid_t pid;
	pid_t  pid_c;
	pid = fork();
	if(pid >0)
	{	
		while(1)
		{
		printf("我是孩子他爹\n");
		printf("父：   pid :%d,ppid :%d \n",getpid(),getppid());
		sleep(1);
//		break;
		}

	}else if(pid == 0)
	{
	//	while(1)
			printf("我是孩子\n");
			printf("子:   pid :%d,ppid :%d \n",getpid(),getppid());
			sleep(2);


			pid_c = fork();
			if(pid_c >0)
			{
				printf(" ---- pid :%d\tppid: %d\n",getpid(),getppid());
			
			}else if(pid_c == 0)
			{
			
				printf(" ++++  pid ：%d ppid %d \n",getpid(),getppid());
			
			}

//			break;
	}else
	{
		perror("fork");
	}

}

