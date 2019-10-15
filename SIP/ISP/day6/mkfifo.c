#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	mkfifo("./FIFO",0666);
	return 0;
}
