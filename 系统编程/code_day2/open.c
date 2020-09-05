#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	
	int fd = open("./f1.txt",O_WRONLY);

	//int fd = open("./f1.txt",O_WRONLY|O_CREAT,0777);
	//0777  配合O_CREAT 使用

	printf("fd = %d\n",fd);

	close(fd);

}

