#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main()
{

	kill(getpid(),9);

	printf("hello world\n");

	return 0;

}
