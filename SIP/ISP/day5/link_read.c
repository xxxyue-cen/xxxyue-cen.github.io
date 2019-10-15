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

int main()
{
	int fd ;
	fd = open("FIFO",O_RDONLY);
	if(fd < 0 )
	{
		perror("open");
		return -1;
	}
	struct node *p= NULL;
	struct node *head =NULL;
	int ret;
	while(1)
	{
		p = malloc(sizeof(struct node));
		
		ret = read(fd,p,sizeof(struct node));
		printf("ret = %d\n",ret);
		if(ret ==0 )
		{
			free(p);
			break;
		}else if(ret < 0 )
		{
		perror("read");
		return -1;
		}
		p->next = head;
		head = p;
	}

	show(head);

	//释放链表
	close(fd);
	return 0;
}



