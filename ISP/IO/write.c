#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>  //write
#include <string.h>

int main()
{

	int fd;
	//O_TRUNC  如果文件有内容则清空
	fd = open("./file.txt",O_WRONLY|O_TRUNC);
	printf("fd = %d\n",fd);
	if(fd <0)
		perror("open");

	char str[20];
	
	int ret;
	gets(str);

	ret = write(fd,str,strlen(str));
	
	if(ret < 0)
	{
		perror("write");
	}

	printf("ret =  %d\n",ret);

	close(fd);
}




