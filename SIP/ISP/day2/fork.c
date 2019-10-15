#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main()
{
	pid_t  pid;

	pid = fork();
	//pid > 0  父进程
	//pid = 0  子进程
	//pid < 0  error 
	int count = 0; 
	if(pid >0)
	{
		printf("这是父进程\n");
		count ++;
		printf("pid = %d,count :%d\n",pid,count);
	}
	else if(pid == 0)
	{
		printf("这是子进程\n");
		count ++;
		printf("pid = %d,count :%d\n",pid,count);
	}
	else if(pid <0)
	{
		perror("fork");
	}

}
