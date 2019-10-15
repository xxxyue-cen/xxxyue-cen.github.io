#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd;
	fd = open("./file.txt",O_WRONLY | O_CREAT,0777);
	//fd = open("./file",O_WRONLY);
	if(fd <0)
		perror("open:");
	else
		perror("open");
}
