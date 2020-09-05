#include <unistd.h>
#include <stdio.h>

int main()
{

	int ret = access("f1",W_OK);
	//R_OK  是否可读
	//W_OK  是否可写
	//X_OK  是否可执行
	//F_OK  是否存在
	//返回值：有： 0
	//				无：-1

	printf("ret = %d\n",ret);

}
