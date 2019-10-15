#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void handle()
{
	printf("get signal\n");
	exit(1);
}

int main()
{

	signal(2,handle);
	raise(SIGINT);//exit(1)


}
