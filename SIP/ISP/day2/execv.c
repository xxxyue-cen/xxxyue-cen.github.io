#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	char *argv[5];
	argv[0] = "ls";
	argv[1] = "/home/yisheng";
	argv[2] = NULL;

	execv("/bin/ls",argv);
	printf("ls end\n");


}
