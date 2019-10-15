#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void handle()
{

	printf("get 13\n");
	exit(1);
}


int main()
{

	signal(13,handle);
	int fd = open("./FIFO",O_RDONLY);
	if(fd < 0 )
	{
		perror("open");
		return -1;
	}
	int ret;
	char buff[128];
	while(1)
	{
	
		ret = read(fd,&buff,sizeof(buff));
		
		printf("ret = %d\n",ret);
		buff[ret] = '\0';
		if(ret == 0)
		{
			perror("FIFO broken\n");
			return -1;
		}else if(ret < 0)
		{
			perror("read");
			return -1;
		}
			
		
		puts(buff);
	}
	close(fd);
}
