#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
  //一个进程可以打开1024个文件  
	//0  stdin   标准输入
	//1  stdout  标准输出
	//2  stderr  标准出错
	//  3 4 5 6 7 。。。 1023    用户可以用的
	
	//int open(char *pathname,int flag)   
	//返回值：文件描述符
	//name： 文件名
	//flag:  文件打开方式
	//O_RDONLY 读     ----> r    -1  说明没有读权限
	//OWRONLY   写    ----> w
	//O_APPEND  追加  ----> a+
	//O_RDWR   读写   ----> a 

	//打开文件
	
	//umask   掩码   0002   0022    限制创建文件的权限   0777-0002 = 775      
	//修改掩码   umask  0022

	int fd;
	//fd = open("temp.txt",O_RDONLY);  //这个文件已经存在了，只需要打开即可
	fd = open("temp.txt",O_CREAT|O_RDONLY,0777); //如果文件不存在，则创建文件    /根目录        ./当前目录（可省略）
	printf("fd = %d\n",fd);
	//关闭文件
	close(fd);
	int std0 =STDIN_FILENO;
	int std1 =STDOUT_FILENO;
	
	printf("std0 = %d\n",std0);
	printf("std1 = %d\n",std1);
}








