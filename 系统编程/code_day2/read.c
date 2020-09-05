//read   读文件，非阻塞函数
//       读管道，读设备，阻塞函数


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = open("f1",O_RDONLY);
	if(fd < 0)
	{
			printf("open error\n");
			return -1;
	}
# if 1
	char str[20];//一次性读取
	int ret = read(fd,str,20);
	printf("ret = %d\n",ret);
	str[ret] = '\0';  //手动加上尾0	
	printf("str = %s",str);
#else
	char ch;//循环读取
	int ret;
	while(1)
	{
		ret = read(fd,&ch,1);
		printf("ret = %d\n",ret);
		if(ret <=0 )
			break;
		putchar(ch);	
	}
#endif
	close(fd);
}








