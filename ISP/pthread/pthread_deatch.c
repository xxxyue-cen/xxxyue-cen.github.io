#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
struct stu
{

	int num;
	char name[32];
};

void *fun(void *arg)
{
	int i =0;
//	int p = *((int *)arg);
	struct stu s1; 
	s1 = *((struct stu *)arg);

	struct stu *pp = malloc(sizeof(struct stu));
	pp->num = s1.num;
	strcpy(pp->name,s1.name);
	
	
	while(1)
	{
		if (i > 5)
		break;		
			//			pthread_exit((void *)pp);


		printf(" pthreadID :%ld pid:%d\n",pthread_self(),getpid());

		printf("this is pthread  [%d|%s]\n",s1.num,s1.name);
		sleep(1);
		i++;
	}
}
 //gcc   pthread_test.c   -lpthread
int main()
{

	pthread_t  thread;
	struct stu *p = NULL;
	p = malloc(sizeof(struct stu));
	p->num = 1001;
	strcpy(p->name,"hello");
	int num = 10;
	//int ret = pthread_create(&thread,NULL,(void *)fun,(void *)&num);
	int ret = pthread_create(&thread,NULL,(void *)fun,(void *)p);
	if(ret < 0)
	{
		perror("pthread");
		return -1;
	}

	pthread_detach(thread);


	while(1)
	{
	
		printf("main  pthreadID :%ld\tpid:%d\n",pthread_self(),getpid());
		printf("this is main\n");
		sleep(2);
	}

}



