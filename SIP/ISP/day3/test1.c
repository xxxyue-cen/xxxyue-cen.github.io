#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{

	pid_t pid;

	char command[32];
	pid = fork();

	if(pid >0 )
	{
		for(int i = 1;i< 11 ; i++ )
		{
			sprintf(command, "mkdir %d",i);
			system(command);
/*
			char *argv[3];
			argv[0] = "mkdir";
			argv[1] = &i;
			argv[2] = NULL;
			execv("/bin/mkdir",argv);			
*/
			sleep(1);
		}
	}else if(pid == 0 )
	{
		for(int i = 1;i< 11 ; i++ )
		{
			sprintf(command, "rmdir %d",i);
			system("ls");
			sleep(2);			
			system(command);		
		}

	}else
	{
	perror("fork");
	
	}
	
	return 0;






}


