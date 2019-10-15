/*
 *编写一个程序实现一个线程实现若干秒 创建一个文件，并对文件内输入一定的内容 
 *另一个线程实现对文件的读取，讲文件内容打印出来，并删除文件
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>

void *create_file()
{
	char temp[32];
	
	for(int i = 0;i <10;i++)
	{
		sprintf(temp,"ls -l>file%d",i);
		system(temp);
	}
	sleep(10);
//	pthread_cancel();
}


void read_file()
{

	int fd;
	char temp[32];
	char buff[2048];
	char command[32];
	int ret;
	for(int i= 0;i<10;i++)
	{
		sleep(1);
		sprintf(temp,"file%d",i);
		fd = open(temp,O_RDONLY);
		if(fd < 0)
		{
			perror("open");
		}
		ret = read(fd,buff,sizeof(buff));
		if(ret == 0)
		{
			break;
		}else if(ret < 0)
		{
			perror("read");
		}else
		{
			buff[ret] = '\0';
			puts(buff);	
		}
		close(fd);
		sprintf(command,"rm -rf file%d",i);
		system(command);
	}
}
/*
 * 
 * pthread_exit((void *))  
 *线程退出，返回值(void *)
 *
 * pthread_detach(pthread_t  pth)
 * 线程分离     (系统回收线程资源)
 *
 *互斥锁
 *
 *  pthread_mutex_t  flag;   
 *	pthread_mutex_init(&flag)    初始化互斥锁
 *	pthread_mutex_lock(&flag)    上锁
 *	pthread_mutex_unlock(&flag)  解锁
 *	pthread_mutex_trylock(&flag) 接触死锁
 */

int main()
{

	pthread_t pth;

	int ret;

	ret = pthread_create(&pth,NULL,(void *)create_file,NULL);
	// 1. pthread_t  * 
	// 2. NULL 线程属性
	// 3. 函数指针  （void *)create_file
	// 4. 函数参数   (void *)
	if(ret < 0)
	{
		perror("pthread_create");
	}
	
	pthread_join(pth,NULL);
	//pthread_t  变量
	//接收线程退出的值   (void **)
	read_file();
}



