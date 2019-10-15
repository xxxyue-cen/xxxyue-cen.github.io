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


#define MENU "1.注册\n"\
	"2.登录\n"\
"请输入选择\n"


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


void log(int fd)
{

	struct pack *p = NULL;
	struct msg ms;
	strcpy(ms.name,"小红");
	strcpy(ms.passwd,"654321");
	//封包

	p = malloc(sizeof(struct pack)+sizeof(struct msg));
	p->type = LOG;
	p->len = sizeof(struct msg);

	//将数据内容封装
	memcpy(p->data,&ms,sizeof(struct msg));


	//发包
	int ret = write(fd,p,sizeof(struct msg)+sizeof(struct pack));
	printf("ret = %d\n",ret);

}



void reg(int fd)
{

	struct pack *p = NULL;
	struct msg ms;
	strcpy(ms.name,"小明");
	strcpy(ms.passwd,"123456");
	//封包

	p = malloc(sizeof(struct pack)+sizeof(struct msg));
	p->type = REG;
	p->len = sizeof(struct msg);

	//将数据内容封装
	memcpy(p->data,&ms,sizeof(struct msg));


	//发包
	int ret = write(fd,p,sizeof(struct msg)+sizeof(struct pack));
	printf("ret = %d\n",ret);

}



int main()
{

	int fd = open("./FIFO",O_WRONLY);
	if(fd < 0 )
	{
		perror("open");
		return -1;
	}


	int i;
	while(1)
	{
		printf("%s\n",MENU);

		scanf("%d",&i);


		switch(i)
		{
			case 1 : reg(fd);
					 break;
			case 2:	log(fd);
					break;



		}
	}



}

