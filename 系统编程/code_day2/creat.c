#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	int fd = creat("f1",0777);   
	//相当于  int fd = open("f1",O_CREAT|O_WRONLY|O_TRUNC,0777);
	printf("fd = %d\n",fd);
	close(fd);
}


