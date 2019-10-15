#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main()
{

  pid_t pid;
  pid = fork();
  if(pid > 0 )
	{
		execl("/bin/ls","ls","-l",NULL);
		
	}else if(pid == 0)
	{
		execl("/usr/bin/gedit","gedit","fork.c",NULL);
	}else
	{
		printf("fork");
	}
}


