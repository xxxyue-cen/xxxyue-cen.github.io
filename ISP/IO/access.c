#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

//  R_OK  可读
//	W_OK  可写
//  X_OK  可执行
//  F_OK  是否存在
//  -1   没有权限
//  0    有权限
	
int main()
{
	int ret;
	ret = access("./file.txt",F_OK);
	printf("ret = %d\n",ret);
}

