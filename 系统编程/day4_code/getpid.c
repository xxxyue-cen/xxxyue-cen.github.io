#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int pid  = getpid();
	printf("pid = %d\n",getpid());//获取当前进程id
	printf("ppid = %d\n",getppid());//获取父进程id
	printf("uid = %d\n",getuid());//获取父进程id
	printf("gid = %d\n",getgid());//获取父进程id
	printf("grp = %d\n",getpgrp());//获取父进程id
	printf("pgid = %d\n",getpgid(pid));//获取父进程id
	while(1);

}
