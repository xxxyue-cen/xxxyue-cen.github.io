#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{

	int fd = open("./FIFO",O_WRONLY);
	if(fd < 0 )
	{
		perror("open");
		return -1;
	}
	int ret;
	char buff[128];
	while(1)
	{
	
		printf("请输入内容:\n");
		scanf("%s",buff);
		ret = write(fd,&buff,strlen(buff));
		printf("ret = %d\n",ret);
		if(ret < 0 )
		{
			perror("write");
			return -1; 
		}
		else
		{
			printf("发送成功!\n");
		}
	}

	close(fd);
}
