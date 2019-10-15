#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	fd = creat("temp.txt",0777);
	if(fd < 0)
		perror("creat");
	else
		perror("creat");
	return 0;
}

