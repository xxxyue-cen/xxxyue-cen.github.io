#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{

	//system("ls -l");

	//		execl("/bin/ls","ls","-l","-a",NULL);
	//	execl("./","hello",NULL);    //path
	//execlp("./hello","hello",NULL);  //path+file	
	//	execlp("/bin/ls","ls","-l",NULL);

	   /*
	   char *argv[2];
		 argv[0] = "hello";
		 argv[1] = NULL;
		 execv("./",argv);
		 */

	char *argv[3];
	argv[0]= "ls";
	argv[1]= "-l";
	argv[2]= NULL;
	execvp("/bin/ls",argv);

	printf("hello world\n");

}









