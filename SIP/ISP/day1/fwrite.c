#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp = NULL;
	fp = fopen("./file","w+");
	if(fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}
	char buff[128];
	int ret;
	printf("输入内容:\n");
	scanf("%s",buff);

	ret = fwrite(buff,strlen(buff),1,fp);
		if(ret <0 )
	{
		perror("fread");
		return -1;
	}
	printf("ret = %d\n",ret);
	puts(buff);
	fclose(fp);
	return 0;
}
