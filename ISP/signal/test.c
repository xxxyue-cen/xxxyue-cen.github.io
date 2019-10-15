/*
 
 安装信号 SIGUSR1
 分裂进程
 子进程：发送信号给父进程
 父进程：
 接收信号，运行学生管理系统，屏蔽SIGINT，SIGTSTP信号


 */


#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle()
{
	printf("get sigusr1\n");
}

int main()
{


	signal(2,SIG_IGN);
	signal(SIGTSTP,SIG_IGN);

	signal(SIGUSR1,handle);
	pid_t pid;
	pid = fork();
	if(pid == 0)
	{
		kill(getppid(),SIGUSR1);
		exit(1);
	}else if(pid > 0)
	{
	
	system("./alarm");

	}



}


