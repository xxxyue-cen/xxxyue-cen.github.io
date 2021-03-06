#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define REG    0x1000
#define LOG    0x2000
#define FND    0x3000


struct pack
{
	int type;
	int len;
	char data[0];
};


struct msg
{
	char name[32];
	char passwd[32];
};


int main()
{

	int fd = open("./FIFO",O_RDONLY);
	if(fd < 0 )
	{
		perror("open");
		return -1;
	}
	struct pack *p = NULL;
	struct msg ms;
	while(1)
	{

	
	//获取包头内容
	p = malloc(sizeof(struct pack));
	
	int ret = read(fd,p,sizeof(struct pack));
	printf("ret =  %d\n",ret);
	if(ret < 0)
	{
		perror("read");
		return -1;
	}else if(ret == 0)
	{
		printf("FIFO broken\n");
		return -1;
	}
	if(p->type == REG)
	{
		
		//通过包头获取数据
		ret = read(fd,&ms,p->len);
		printf("ret = %d %d \n",ret,__LINE__);
		printf("name :%s passwd :%s \n ",ms.name,ms.passwd);
	
	}else if(p->type == LOG)
	{
			//通过包头获取数据
		ret = read(fd,&ms,p->len);
		printf("ret = %d %d \n",ret,__LINE__);
		printf("name :%s passwd :%s \n ",ms.name,ms.passwd);	
	}

	}
}






