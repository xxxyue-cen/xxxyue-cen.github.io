#include <stdio.h>
#include <unistd.h>

int main()
{

	char str[20];
	int ret = read(0,str,sizeof(str));
	printf("ret =  %d\n",ret);

	str[ret] = '\0';
	printf("str: %s\n",str);
	
	return 0;
}

