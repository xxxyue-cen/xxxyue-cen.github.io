#include <unistd.h>
#include <stdio.h>
#include <string.h>
struct stu
{
	int num;
	char name[32];
	char sex;

};

int main()
{

	FILE *fp = fopen("./file1","r");

	struct stu s1={1001,"abc",'M'};
	struct stu s2;


//fprintf(fp,"%d%s",s1.num,s1.name);
	fscanf(fp,"%d%s",&s2.num,s2.name);

	s2.name[strlen(s2.name)] ='\0';
	printf("num:%d %s\n",s2.num,s2.name);

	fclose(fp);

}
