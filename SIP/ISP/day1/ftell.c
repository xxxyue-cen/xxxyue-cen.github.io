#include <stdio.h>
#include <unistd.h>


/*  open 
 *  write
 *  read
 *  close
 * 
 *  fopen
 *  fread
 *  fwrite
 *  fclose
 * 
 *	read    阻塞函数
 *	scanf   阻塞函数
 *	getchar()
 * 	
 *	gets    非阻塞函数
 *
 *	int a;
 *	scanf("%d",&a);
 */





int main()
{


	FILE *fp = fopen("./file","r");

	int a;

	fseek(fp,5,SEEK_SET);
	
	a = ftell(fp);

	printf("a = %d\n",a);
	
	fclose(fp);
}

