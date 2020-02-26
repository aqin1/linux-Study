#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>


int main(int argc,char *argv[])
{
	extern int errno;
	pid_t tpid;
	int twstatus;
	int exe_flag;
	tpid = fork();
	if(tpid == -1)
	{
		perror("fork");
		return -1;
	}
	if(tpid == 0)
	{
		tpid = getpid();
		printf("This is child and PID is %d\n",tpid);
		exe_flag = execlp("ls","ls","-l","/home",NULL);
		//若成功调用execlp，该程序后面的代码都不会被执行
		if(!errno)
			perror("execl");
		else
		{
			printf("execl succeed!\n");
		}
		return 0;
	}
	else
	{
		tpid = getpid();
		printf("This is father and PID is %d\n",tpid);
		printf("Wait for child exit\n");
		if((tpid = wait(&twstatus)) == -1)
			perror("Wait");
		else
		{
			if(!WIFEXITED(twstatus))
				printf("wait failed!\n");
			printf("wait succeed,child's pid is %d\n",tpid);
			printf("twstatus=%d\n",twstatus);
		}
		printf("errno=%d,EOF=%d\n",errno,EOF);
		return 0;
	}
	return 0;
}

