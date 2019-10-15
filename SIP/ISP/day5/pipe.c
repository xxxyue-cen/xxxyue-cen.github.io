#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>

void handle()
{
	printf("get SIGPIPE\n");
	exit(1);
}

int main()
{
	signal(SIGPIPE,handle);
	int fd[2];
	pipe(fd);
	pid_t pid;
	pid = fork();
	if(pid > 0)
	{
		close(fd[0]);
		while(1)
		write(fd[1],"hello",5);
		close(fd[1]);

	}else if(pid ==0)
	{
		char buff[10];
		close(fd[1]);
		while(1)
		read(fd[0],buff,5);
		buff[5]='\0';
		puts(buff);
		close(fd[0]);
	}
}
