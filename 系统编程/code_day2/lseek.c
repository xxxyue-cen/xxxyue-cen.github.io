#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = open("f2",O_RDONLY);
	if(fd < 0)
	{
			printf("open error\n");
			return -1;
	}

	//lseek(fd,1,SEEK_SET);//文件指针从开头移到第二的位置

	lseek(fd,-5,SEEK_END);//文件指针从末尾上移一个字符的位置

	char str[20];
	int ret = read(fd,str,20);
	str[ret-1] = '\0';
	printf("str = %s\n",str);
	
	close(fd);
}








