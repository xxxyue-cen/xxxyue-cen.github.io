# **系统编程**

# **系统I\O**

## **1.文件打开**

####  **1.1 open**

##### **概述 ：按照指定权限打开一个文件，返回一个文件描述符**

```c

    #includ e <sys/types.h>
    
    #include <sys/stat.h>

    #include <fcntl.h>
       
    int open(const char *pathname, int flags);
    
    int open(const char *pathname, int flags, mode_t mode)
    
    int creat(const char *pathname, mode_t mode);
```

pathname : 文件名称

flags : 文件打开标志

返回值 : 文件打开的描述符
```c
eg : int fd = open("./temp",O_RDONLY);
```
## **文件读**

####  **1.2 read**

##### **概述 ：从文件中读取，然后将文件内容存入指定的变量中**

```
    #include <unistd.h>

    ssize_t read(int fd, void *buf, isize_t count);

```

fd : 文件描述符

buf : 读取的内容存的位置

count : 读取的数据大小

返回值 : 读取到的字节
      
```c
> 0 读取的字节数  
= 0 读到文件末尾
< 0 读取错误
```
```c
eg : int ret =  read(fd,buff,10);
```
## **文件写**

#### **1.3 write**

##### **概述 ：将数据内容写入文件**

```c
    #include <unistd.h>

    ssize_t write(int fd, const void *buf, size_t count);

```

fd : 文件描述符

buf : 写入的内容

count : 写入的字节数

返回值 : > 0  写入的字节数
              < 0   写入失败
```c
eg : int ret =  write(fd,buff,10); 
```
## **文件关闭**

#### **1.4 close**

##### **概述 : 关闭文件描述符**

```c
    #include <unistd.h>

    int close(int fd);

```
fd : 文件描述符
```c
eg : close(fd);
```
## **文件指针偏移**

#### **1.5  lseek**

##### **概述：将文件指针移动到指定的偏移位置** 

```c
       #include <sys/types.h>
       
       #include <unistd.h>

       off_t lseek(int fd, off_t offset, int whence);
```

fd ：文件描述符

offset : 指针偏移量

whence ：指针基准点（起始位置）

```c
eg ：lseek（fd , 10 , SEEK_SET  ） 
```


# **进程**

## **获取进程id的函数**

```c
    #include <unistd.h>
    #include <sys/types.h>

    uid_t getuid(void)：获得进程的用户标识号。
    gid_t getgid(void)：获得进程的用户所属的用户组ID。 
    pid_t getpid(void)：要获得当前进程的ID。
    pid_t getppid(void)：获得当前进程的父进程的ID。
    pid_t getpgrp(void)：获得当前进程所在的进程组的ID。
    pid_t getpgid(pid_t pid)：获得进程ID为pid的进程所在的进程组ID。

    pid_t     进程id数据类型
    
```

## **进程创建**

#### **1.fork**

#### **概述 ：进程分裂，创建一个子进程**

```c
     #include <unistd.h>

      pid_t fork(void);
```

void : 参数传空（void）

返回值:   > 0  返回父进程的pid
         == 0  表示子进程
         < 0 进程分裂失败

```c
eg : pid = fork();
```
## **执行某个文件**

#### **2.exec**

#### **概述 ：**

```c
    #include <unistd.h>

    extern char **environ;

    int execl( const char *path, const char *arg, ...);
    
    int execlp( const char *file, const char *arg, ...);
    
    int execle( const char *path, const char *arg , ..., char * const envp[]);
    
    int execv( const char *path, char *const argv[]);
    
    int execvp( const char *file, char *const argv[]);

```

path : 文件路径

arg : 命令内容

argv[] : 命令数组

最后一个参数必须传NULL
```c
eg ：execl("/bin/ls","ls",NULL);
```

## **进程退出**

#### **3. exit**

#### **概述 ：调用次函数使得进程正常退出**

```c
    #include <stdlib.h>

    void exit(int status);
```

status : 进程终止返回值
```c
eg : exit(1);
```
## **等待进程结束**

#### **4. wait**

#### **概述 :  等待(子)进程退出**

```c
    #include <sys/types.h>
    
    #include <sys/wait.h>

    pid_t wait(int *status);

    pid_t waitpid(pid_t pid, int *status, int options);
```

status : exit函数的参数

pid : 指定进程退出的进程号

option ：获取进程退出的状态
```c
eg ：wait(NULL);
```
# **线程**

## **线程创建**

#### **1.pthread_create**

#### **概述 ：创建一个线程**

```c
    #include <pthread.h>

    int pthread_create(pthread_t *thread, const pthread_attr_t *attr, 		void *(*start_routine) (void *), void *arg);
```

thread : 线程id

attr ：线程属性

*start_routine : 函数指针

*arg ：函数的参数
```c
eg： pthread_create(&pth,NULL,fun,NULL);
```
## **线程退出**

#### **2. pthread_exit**

#### **概述 ：线程退出**

```c
    #include <pthread.h>

    void pthread_exit(void *retval);
```

reval : 线程退出的返回值
```c
eg ： pthread_exit(int(*)a );
```
## **线程等待**

#### **3. pthread_join**

#### **概述 ：等待线程结束**

```c
    #include <pthread.h>

    int pthread_join(pthread_t thread, void **retval);
```
thread : 指定线程退出的线程号

**retval : 接收线程退出的返回值
```c
eg ： pthread_join(pth,NULL);
```

## **获取线程自己的编号**

#### **4. pthread_self**

#### **概述 : 获取本线程的id**
```c
    #include <pthread.h>

    pthread_t pthread_self(void);
```

返回值 ： 本线程的id
```c
eg ：pth = pthread_self();
```

# **进程间通信**

# **信号**

## **1.signal**

## **概述 : 信号安装**

```c
    #include <signal.h>

    typedef void (*sighandler_t)(int);

    sighandler_t signal(int signum, sighandler_t handler);
```

signum:信号值

handler：信号处理函数
	   
        SIG_IGN  忽略信号
       
        SIG_DFL  默认省缺值
```c
eg : signal(SIGINT,handler);
```

## 信号（发送）产生

```c
kill（pid_t pid,int sig）   //sig
raise（int sig）            //sig
alarm（int second）         //SIGALRM
setitimer（）               //SIGALRM
abort（）                   //SIGABRT
```

## 文件锁
```c
    #include <unistd.h>
    #include <fcntl.h>

    int fcntl(int fd, int cmd, ... /* arg */ );

    int fcntl（int fd，int cmd，struct flock *lock）

```
fd:文件描述符

cmd:文件锁状态 

```c    
    F_GETLK  获取锁的状态
     
    F_SETLK  上锁（非阻塞）
     
    F_SETLKW 阻塞上锁
```
```c	
struct flock {
           	//锁的类型
               short l_type;    /* Type of lock: F_RDLCK,
                                   F_WRLCK, F_UNLCK */
               //文件指针的基准点
		short l_whence;  /* How to interpret l_start:
                                   SEEK_SET, SEEK_CUR, SEEK_END */
               //文件指针的开始位置
		off_t l_start;   /* Starting offset for lock */
            	//加锁的长度
		off_t l_len;     /* Number of bytes to lock */
               //进程号
		pid_t l_pid;     /* PID of process blocking our lock
                                   (set by F_GETLK and F_OFD_GETLK) */   
           };
```


## FIFO（任何进程之间） 
1.mkfifo("FIFO",0777)   //创建管道

system I\O   open   read  write  close

c库 I\O       fopen   fscanf   fprintf   fclose


## PIPE（亲子进程之间）
2.
int fd[2];
int pipe(fd);
fd[0] 读端
fd[1] 写端

ipc：
key_t  key = ftok(pathname,int proj_id)  

pathname: 任何目录  

proj_id： 1-255

eg:key = ftok("./",125);  

# 信号量：
### 1.创建信号量：
```c
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/sem.h>

    int semget(key_t key, int nsems, int semflg);
```
key  ：ftok（）返回值

nsems : 信号量个数

semflg ：信号量创建标志 
```c
	IPC_CREAT   创建
	
	IPC_EXCL    当和IPC_CREAT一起使用时，如果信号量已经存在，则返回错误。
```
返回值：信号量id


eg： semid = semget(key,1,IPC_CREAT|0666);


### 2.信号量操作函数
```c
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/sem.h>

    int semop(int semid, struct sembuf *sops, size_t nsops);
```

semid: 信号量id

struct sembuf *sops：信号量结构体数组地址

size_t nsops：数组长度

```c
struct sembuf{
 	        unsigned short sem_num;  /* semaphore number   信号量编号  */
            short  sem_op;   /* semaphore operation v操作   +1  -1  0 +2  -2 */
            short  sem_flg;  
					/* operation flags    信号量状态  阻塞或非阻塞  
					IPC_NOWAIT 阻塞状态
					SEM_UNDO.  可撤销（进程结束，如果信号量没有释放，系统会自动释放）
					*/
}；
```
```c
struct sembuf sops[1];

sops.sem_num = 0;

sops.sem_op = +1;

sops.sem_flg = 0;(阻塞)

eg: semop(semid,sops,1);
```
## 3.信号量控制
```c
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/sem.h>

    int semctl(int semid, int semnum, int cmd, ...);
```

semid: 信号量id

semnum：信号量个数

cmd：操作标志

     IPC_STAT : 获取信号量状态（struct semid_ds）
     IPC_SET  ：设置信号量状态（struct ipc_perm）
     IPC_RMID ：删除信号量   （NULL）

```c
eg:semctl(semid,1,IPC_RMID)
```

# 消息队列
## 1.创建消息队列
```c
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/msg.h>

    int msgget(key_t key, int msgflg);
```

key：ftok()返回值

msgflg:信号量创建标志 

```c
IPC_CREAT   创建
IPC_EXCL    当和IPC_CREAT一起使用时，如果信号量已经存在，则返回错误。
```

返回值：消息队列id

```c
eg：msqid =  msgget（key，IPC_CREAT|0666）；
```

## 2.发送消息：
```c
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/msg.h>

    int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
```
msqid:消息队列id

struct msgbuf *msgp：消息内容

msgsz：消息的真实大小（不包括类型）

msgflg：消息状态 0 阻塞状态

```c
struct msgbuf {
               long mtype;       /* message type, must be > 0 */类型（必须大于 0 ）
               char mtext[1];    /* message data */可自定义大小
           };

eg:msgsnd(msqid,&msgp,sizeof(struct msgbuf)-sizeof(long),0);
```
## 3.接收消息
```c
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/msg.h>

    ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,int msgflg);
```
msqid:消息队列id

struct msgbuf *msgp：消息结构体

msgsz：消息的真实大小（不包括类型）

msgtype：消息类型

msgflg：消息状态 0 阻塞状态

```c
eg：msgrcv（msqid，&msgq，sizeof(struct msgbuf)-sizeof(long)，1,0）；
```

## 4.消息队列控制
```c
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/msg.h>

    int msgctl(int msqid, int cmd, struct msqid_ds *buf);
```
msqid:消息队列id

cmd：操作标志

```c
 IPC_STAT : 获取信号量状态（struct msqid_ds）
 IPC_SET  ：设置信号量状态（struct msqid_ds）
 IPC_RMID ：删除信号量   （NULL）
```

```c
eg：msgctl（msqid，IPC_RMID，NULL）;
```

# 共享内存
## 1.共享内存创建
```c
    #include <sys/ipc.h>
    #include <sys/shm.h>

    int shmget(key_t key, size_t size, int shmflg);
```

key:ftok()返回值

size：共享内存大小

shmflg：共享内存创建标志 

	IPC_CREAT   创建
	IPC_EXCL    当和IPC_CREAT一起使用时，如果共享内存已经存在，则返回错误。

返回值：共享内存队列id

```c
eg:shmid = shmget(key,1024,IPC_CREAT|0666); 
```
## 2.连接共享内存
```c
    #include <sys/types.h>
    #include <sys/shm.h>

    void *shmat(int shmid, const void *shmaddr, int shmflg);
```

shmid:共享内存id

shmaddr:存在内存中的地址，一般设置成NULL，由内核分配

shmflg：共享内存状态

返回值：返回指向内存的地址

```c
eg：char *p = shmat(shmid,NULL,0);
```

## 3.共享内存分离
```c
    #include <sys/types.h>
    #include <sys/shm.h>

    int shmdt(const void *shmaddr);
```
shmaddr:指向共享内存的指针

```c
eg：shmdt（p）；
```

## 4.删除共享内存
```c
    #include <sys/ipc.h>
    #include <sys/shm.h>

    int shmctl(int shmid, int cmd, struct shmid_ds *buf);
```
shmid：共享内存id

cmd：对共享内存操作标志

 	IPC_STAT : 获取共享内存状态（struct shmid_ds）
    IPC_SET  ：设置共享内存状态（struct shmid_ds）
    IPC_RMID ：删除共享内存   （NULL）

```c
eg：shmctl（shmid，IPC_RMID，NULL）;     
```
