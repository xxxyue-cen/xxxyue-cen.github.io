#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

//创建管道文件
int main()
{

	int ret = mkfifo("./FIFO",0777);
	if(ret < 0)
	{
		perror("mkfifo");
		return -1;
	}
	perror("mkfifo");

}

