//打开文件
//写
//关闭文件


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main()
{
	int fd = open("./f1",O_CREAT|O_WRONLY,0777);//打开  O_APPEND
	if(fd < 0)
	{
		printf("open error\n");
		return -1;
	}
	
	char str[20] ="hello world";
	int ret = write(fd,str,strlen(str));//写
	//fd： 文件描述符     1  
	//const void *str：写入的内容
	//strlen(str): 写入的长度
	//返回值：成功：写入的数据的大小，失败：-1
	printf("ret = %d\n",ret);
	
	close(fd);//关闭
}
