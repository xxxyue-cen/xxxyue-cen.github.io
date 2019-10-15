#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
struct node 
{
	int num;
	struct node *next;
};


void show(struct node *head)
{
	struct node *p = head;
	while(p != NULL)
	{
		printf("[%d|%p]\n",p->num,p->next);
		p = p->next;
	}
}

void link_write(struct node *head)
{
	struct node *p = head;
	int fd;

	fd = open("./file",O_WRONLY|O_CREAT,0664);
	if(fd < 0 )
	{
		perror("open");
		return ;
	}
	int ret;
	while(p != NULL)
	{
	
		ret = write(fd,p,sizeof(struct node));
//		printf("ret = %d\n",ret);
		if(ret < 0)
		{
			perror("write");
			break;
		}
		p = p->next;
	}

	close(fd);
}



void creat_link()
{

	struct node *p = NULL;
	struct node *head = NULL;

	for(int i = 0;i < 100;i++)
	{
		p = malloc(sizeof(struct node));
		p->num = i ;
	
		p->next = head;
		head = p;
	}	
//	show(head);
	link_write(head);
}


void read_link()
{

	int fd;
	struct node *p = NULL;
	struct node *head = NULL;
	fd = open("./file",O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return ;
	}
	int ret;
	while(1)
	{
		p = malloc(sizeof(struct node));
		ret = read(fd,p,sizeof(struct node));
		printf("ret = %d\n",ret);
		if(ret < 0 )
		{
			perror("read");
			return ;
		}else if(ret ==0)
		{
		free(p);
		break;
		}
	
		p ->next = head;
		head = p;
	}

	show(head);

}



int main()
{
	int ret;
	pid_t pid;
	pid = fork();
	if(pid >0 )
	{
		//读取链表
		//wait(NULL);
		waitpid(0,&ret,0);
		read_link();	
	
	}else if(pid == 0)
	{
		//创建链表
		creat_link();
	
	}else 
	{
		perror("fork");
	
	}
	return 0;
}




