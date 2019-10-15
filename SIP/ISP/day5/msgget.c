#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

struct msgbuf
{
	long mtype;
	char buff[20];
};


int main()
{

	//创建键值
	key_t key;
	key = ftok("./",120);
	//创建消息队列
	int msqid = msgget(key,IPC_CREAT|0666);
	if(msqid < 0)
	{
		perror("msgget");
		return -1;
	}
	printf("msqid :%d\n",msqid);
	struct msgbuf msg;
	msg.mtype = 1;
	strcpy(msg.buff,"hello");

	printf("msg: %lu\n",sizeof(msg));
	msgsnd(msqid,&msg,sizeof(msg)-sizeof(long),0);
	//msqid  消息队列编号
	//&msg   消息的结构体地址
	//  消息的真实大小，不包括类型
	//0 状态
	struct msgbuf buf;

	msgrcv(msqid,&buf,sizeof(buf)-sizeof(long),1,0);
	//
	//
	//1  消息的类型
	//
	printf("buff:%s\n",buf.buff);

	msgctl(msqid,IPC_RMID,NULL);	
	//msqid 消息队列id
	//IPC_RMID  删除消息队列       NULL
	//IPC_SET   改变消息对列状态   struct msqid_ds  *buf 
	//IPC_STAT  获取消息队列状态   struct msqid_ds  *buf

}
