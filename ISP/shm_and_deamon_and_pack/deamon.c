#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h> 
#include <sys/param.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
void init_daemon() 
{ 
    int pid; 
	int i;

	signal(SIGINT,SIG_IGN);
	signal(SIGTSTP,SIG_IGN);

	/* 处理SIGCHLD信号。处理SIGCHLD信号并不是必须的。但对于某些进程，特别是服务器进程往往在请求到来时生成子进程处理请求。如果父进程不等待子进程结束，子进程将成为僵尸进程（zombie）从而占用系统资源。*/
	
	if(signal(SIGCHLD,SIG_IGN) == SIG_ERR){
		printf("Cant signal in init_daemon.");
		exit(1);
	}

	if(pid=fork()) 
		exit(0);//是父进程，结束父进程 
	else if(pid< 0){ 
		perror("fail to fork1");
		exit(1);//fork失败，退出
	}
	//是第一子进程，后台继续执行
	setsid();//第一子进程成为新的会话组长和进程组长 
	//并与控制终端分离 
	if(pid=fork()) 
		exit(0);//是第一子进程，结束第一子进程 
	else if(pid< 0) 
		exit(1);//fork失败，退出 
	//是第二子进程，继续 
	//第二子进程不再是会话组长 

	for(i=0;i< getdtablesize();++i)//关闭打开的文件描述符 
		close(i); 
	chdir("/tmp");//改变工作目录到/tmp 
	umask(0);//重设文件创建掩模 
	return; 
}


int main()
{

	init_daemon();
	for(int i = 0;;i++)
	{
	
		printf("i= %d\n",i);
	}



}
