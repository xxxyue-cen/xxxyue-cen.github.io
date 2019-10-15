#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp = NULL;
	fp = fopen("./file","r");
	if(fp == NULL)
	{
		printf("fopen error\n");
		return -1;
	}
	char buff[128];
	int ret;
	char *str;
	
	
	str =   fgets(buff,128,fp);
	
	printf("str = %s\n",str);
	puts(buff);
	fclose(fp);
	return 0;
}
