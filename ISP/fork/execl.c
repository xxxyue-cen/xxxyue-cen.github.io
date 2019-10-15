#include <unistd.h>
#include <stdio.h>

int main()
{

	execl("/bin/ls","ls","-a",NULL);

	printf("ls end\n");

}
