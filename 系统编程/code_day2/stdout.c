#include <unistd.h>
#include <stdio.h>

int main()
{
  //1  标准输出   常开
	char str[20] = "1234567";
	//close(1);
	int ret = write(1,str,sizeof(str));
	printf("ret  = %d\n",ret);

}

