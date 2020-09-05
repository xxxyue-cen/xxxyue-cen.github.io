#include <stdio.h>
#include <unistd.h>

int main()
{
	char str[20];
	int ret = read(0,str,1024);//从标准输入读取
	str[ret]= '\0';
//	str[ret-1]= '\0';
	printf("str = %s\n",str);

}
