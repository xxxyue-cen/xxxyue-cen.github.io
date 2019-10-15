#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>


int main()
{

	//创建键值
	key_t key;
	key = ftok("./",125);
	//创建信号量
	int semid = semget(key,1,IPC_CREAT|0666);
	if(semid < 0)
	{
		perror("semget");
		return -1;

	}
	printf("semid = %d\n",semid);
	//信号量操作
	struct sembuf sops[2];

	sops[0].sem_num = 0;//信号量编号  0,1,2        /* Operate on semaphore 0 */
	sops[0].sem_op = 0; //信号量操作  +1  -1  0  +2  -2         /* Wait for value to equal 0 */
	sops[0].sem_flg = 0;//阻塞状态   
						//	IPC_NOWAIT    0
						//	SEM_UNDO   如果进程突然退出，没有释放信号量，系统会自动释放

	sops[1].sem_num = 0;        /* Operate on semaphore 0 */
	sops[1].sem_op = 1;         /* Increment value by one */
	sops[1].sem_flg = 0;
	
	semop(semid, sops, 2);
	//semid  信号量编号
	//sops   信号量数组的地址 
	//2      数组长度

	//对信号量删除
	semctl(semid,1,IPC_RMID,NULL);
}

