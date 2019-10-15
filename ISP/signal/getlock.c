#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#if 0

struct flock {
	short l_type;    /* Type of lock: F_RDLCK,F_WRLCK, F_UNLCK */
	short l_whence;  /* How to interpret l_start SEEK_SET, SEEK_CUR, SEEK_END */
	off_t l_start;   /* Starting offset for lock */
	off_t l_len;     /* Number of bytes to lock */
};

#endif


void getlock(int fd,struct flock lock)
{

		
	struct flock lock1;
	lock1.l_type = F_RDLCK;
	lock1.l_whence = lock.l_whence;
	lock1.l_start = lock.l_start;
	lock1.l_len = lock.l_len;

	printf("fd = %d\n",fd);
	int ret = fcntl(fd,F_GETLK,&lock1);

//	printf("ret = %d\n",ret);
	perror("fcntl");
	switch(lock1.l_type)
	{
		case F_RDLCK:printf("读锁\n");break;
		case F_WRLCK:printf("写锁\n");break;	
		case F_UNLCK:printf("解锁\n");break;	
		default:printf("other\n");break;
	}
}



int main()
{

	int fd;
	fd = open("./temp",O_RDONLY);
	if(fd < 0)
	{
		perror("open");
	}
//定义文件锁参数
	struct flock lock;
//设置锁的类型    读锁
	lock.l_type = F_RDLCK;
//设置文件指针基准点
	lock.l_whence = SEEK_SET;
//设置锁的开始位置
	lock.l_start = 0;
//设置加锁长度
	lock.l_len = 0;
//上锁  写锁

	/*
	对整个文件加锁   
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	*/
	int ret = fcntl(fd,F_SETLKW,&lock);
	printf("ret =  %d\n",ret);
	
	getlock(fd,lock);

	sleep(1);
	char buff[20];
	ret = read(fd,&buff,12);
	buff[ret]='\0';
	printf("ret = %d\n",ret);
	puts(buff);

	
	//定义文件锁参数
	struct flock unlock;
//定义锁的类型   解锁
	unlock.l_type = F_UNLCK;
	unlock.l_whence = SEEK_SET;
	unlock.l_start = 0;
	unlock.l_len = 0;
//解锁
	fcntl(fd,F_SETLKW,&unlock);
	
	close(fd);

}
