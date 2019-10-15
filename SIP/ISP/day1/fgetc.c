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
	char buff;
	char str[10];
	int i = 0;
	int ret;
	while( EOF !=(buff = fgetc(fp))) 
	{
	str[i] = buff;
	i++;
	}
	str[i]='\0';
	puts(str);
	fclose(fp);
	return 0;
}
