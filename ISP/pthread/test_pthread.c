//用线程实现一个线程创建目录，另一个线程删除目录


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void  rmdir_dir()
{
	
	char command[32];
	for(int i = 0;i<10;i++)
	{
		sprintf(command,"rmdir %d",i);
		sleep(2);
		system(command);

	}
}

void  *mkdir_dir(void *argv)
{
	
	char command[32];
	for(int i = 0;i<10;i++)
	{
		sprintf(command,"mkdir %d",i);
		system(command);
		sleep(1);
	}
}


int main()
{

	pthread_t pid;

	int ret = pthread_create(&pid,NULL,(void *)mkdir_dir,NULL);
	if(ret < 0 )
	{
		perror("pthread");
		return -1;
	}

	rmdir_dir();
	pthread_join(pid,NULL);

}








