//1.打开文件   open
//2.读/写      write/read
//3.关闭文件   close

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{

	int fd;
	fd = open("./file.txt",O_RDONLY);
	if(fd < 0 )
	{
		perror("open");
		return -1;
	}
//

	lseek(fd,3,SEEK_SET);

//
	int ret;
	char str[20];
	ret = read(fd,str,sizeof(str));
	if(ret < 0 )
	{
		perror("read");
		return -1;
	}
	str[ret] = '\0';

	printf("str = %s\n",str);

	return 0;

}
