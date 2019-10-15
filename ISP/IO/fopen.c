#include <stdio.h>


int main()
{
	FILE *fp = NULL;
	fp = fopen("./file.txt","r");
	if(fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}
	
	char buff[128];
	int ret;
	ret = fread(buff,sizeof(buff),1,fp);
	if(ret <0 )
	{
		perror("fread");
		return -1;
	}
	puts(buff);
	fclose(fp);

	return 0;

}
