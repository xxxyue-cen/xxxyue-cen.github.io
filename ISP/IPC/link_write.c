#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct node 
{
	int num;
	char name[32];
	struct node *next;

};


void show(struct node *head)
{
	struct node *p =head;
	while(p!= NULL)
	{
		printf("[num:%d | name:%s|address:%p]\n",p->num,p->name,p->next);
		p = p->next; 
	}
}





int link_write(struct node *head)
{

	int fd;
	fd = open("FIFO",O_WRONLY);
	if(fd <0 )
	{
		perror("open");
		return -1;
	}
	struct node *p = head;
	int ret;
	while(p!= NULL)
	{
	
		ret = write(fd,p,sizeof(struct node));
		printf("ret = %d\n",ret);
		if(ret < 0)
		{
		perror("write");
		return -1;
		}
	p = p->next;
	}

	close(fd);
}





int main()
{
	struct node *p=NULL;
	struct node *head=NULL;

	char ch = 'y';
	while(ch == 'y')
	{
		p = malloc(sizeof(struct node));
		printf("请输入学号:\n");
		scanf("%d",&(p->num));
		printf("请输入姓名:\n");
		scanf("%s",p->name);
		
		p->next = head;
		head = p;
		getchar();
		printf("是否继续?");
		ch = getchar();
	}


	show(head);
	link_write(head);

	//释放链表

}
