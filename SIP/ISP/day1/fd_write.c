#include <stdio.h>
#include <unistd.h>

int main()
{

	int ret;
	ret = write(1,"hello world\n",13);
	printf("ret = %d\n",ret);

}
