#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

int main()
{

	key_t key = ftok("./",123);
	int shmid = shmget(key,1024,IPC_CREAT|0666);
	if(shmid < 0 )
	{
		perror("shmget");
		return -1;
	}
	printf("shmid:%d\n",shmid);
	
	char *p;
	p = shmat(shmid,NULL,0);

	strcpy(p,"hello");

	return 0;
}

