#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int pid = fork();
	if(pid > 0)
	{

		system("ls -l");
	//system(command)
	//command: ls  -l    ps -ef     mkdir   pwd   a.out
	
	//exec()
	

	}else if(pid == 0)
	{
	
		system("ps -aux");
	
	}else
	{
		perror("fork");
		return -1;
	}

}
