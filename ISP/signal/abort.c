#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void handle()
{
	printf("get signal\n");
//	exit(1);
}


int main()
{

	signal(SIGABRT,handle);

	abort();
	
	sleep(3);

}
