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



int main()
{

	int fd = open("./FIFO",O_WRONLY);
	if(fd < 0 )
	{
		perror("open");
		return -1;
	}
//封包
	struct pack *p = NULL;
	char buff[32];

	strcpy(buff,"hello world");
	
	p = malloc(sizeof(struct pack)+strlen(buff));
	p->type = REG;
	p->len = strlen(buff);
    //将数据内容封装
	memcpy(p->data,buff,strlen(buff));	
	
	//发包
	int ret ;
	ret = write(fd,p,sizeof(struct pack)+strlen(buff));
	printf("ret = %d\n",ret);



	










}






