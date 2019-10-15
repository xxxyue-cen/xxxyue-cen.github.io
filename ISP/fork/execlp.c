#include <unistd.h>
#include <stdio.h>

int main()
{

	execlp("ls","ls","-a",NULL);
	//execl("/bin/ls","ls","-a",NULL);
	
	printf("ls end\n");

}
