#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>

/*
pthread_mutex_t  mutex;定义变量
pthread_mutex_init(&mutex);初始化互斥锁
pthread_mutex_lock(&mutex);上锁
pthread_mutex_unlock(&mutex);解锁 

 */




pthread_mutex_t  mutex;


void *read_file1()
{
	pthread_mutex_lock(&mutex);
	int fd = open("temp",O_RDONLY);
	if(fd < 0)
	{
		perror("open");	
	}
	int ret ;
	int a;
	lseek(fd,20,SEEK_SET);
	while(1)
	{
		ret = read(fd,&a,sizeof(int));
		if(ret ==0)
			break;
		else if(ret > 0)
		{
			printf("a = %d\n",a);
		}else 
			perror("read");
	}
	close(fd);
	pthread_mutex_unlock(&mutex);
}




void *read_file()
{

//上锁
	pthread_mutex_lock(&mutex);  //flag = 1
	int fd = open("temp",O_RDONLY);
	if(fd < 0)
	{
		perror("open");	
	}
	int ret ;
	int a;
	while(1)
	{
		ret = read(fd,&a,sizeof(int));
		if(ret ==0)
			break;
		else if(ret > 0)
		{
			printf("a = %d\n",a);
		}else 
			perror("read");
	}
	close(fd);
	//解锁
	pthread_mutex_unlock(&mutex);//flag  = 0
}

void write_file()
{

	
	pthread_mutex_lock(&mutex);
	int fd ;
	fd = open("temp",O_WRONLY|O_CREAT,0664);
	if(fd < 0 )
	{
		perror("open");
	}
	int ret;
	for(int i = 0;i<100;i++)
	{
		ret = write(fd,&i,sizeof(int));
		if(ret < 0)
		{
			perror("write");
			return ;
		}
	}
	close(fd);
	pthread_mutex_unlock(&mutex);
}
int main()
{

	pthread_mutex_init(&mutex,NULL);//初始化互斥锁

	pthread_t pth,pth1;
	int ret = pthread_create(&pth,NULL,(void *)read_file,NULL);
	ret = pthread_create(&pth1,NULL,(void *)read_file1,NULL);
	
	if(ret < 0 )	
	{
		perror("pthread_create");
		return -1;
	}
	write_file();

	pthread_mutex_trylock(&mutex);

	pthread_join(pth,NULL);
	pthread_join(pth1,NULL);
}

