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


int main()
{

	int fd;
	fd = open("./temp",O_WRONLY|O_CREAT,0777);
	if(fd < 0)
	{
		perror("open");
	}
//定义文件锁参数
	struct flock lock;
//设置锁的类型    写锁
	lock.l_type = F_WRLCK;
//设置文件指针基准点
	lock.l_whence = SEEK_SET;
//设置锁的开始位置
	lock.l_start = 0;
//设置加锁长度
	lock.l_len = 100;
//上锁  写锁
	fcntl(fd,F_SETLKW,&lock);
	int ret;
	
	ret = write(fd,"hello world",12);
	printf("ret = %d\n",ret);

//定义文件锁参数
	struct flock unlock;
//定义锁的类型   解锁
	unlock.l_type = F_UNLCK;
	unlock.l_whence = SEEK_SET;
	unlock.l_start = 0;
	unlock.l_len = 100;
//解锁
	fcntl(fd,F_SETLKW,&unlock);
	
	close(fd);

}
