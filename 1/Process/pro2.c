//实现一个shell，在父进程(shell)中创建子进程，子进程执行外部程序(ls)或可执行文件
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc,char *argv[])
{
	pid_t tpid;
	char tcmd[150]="";
	char *cmd[50];
	int cmdlen = 0;
	int i = 0;
	int j;
	int twstatus;
	while(1)
	{
		j = 0;
		printf("Input exe :");
		//读取输入的命令
		if(fgets(tcmd,150,stdin) == NULL)
			perror("fgets");
		cmdlen = strlen(tcmd);
		cmd[j++] = &tcmd[0];
		//生成按参数形式的命令
		for(i=0;i<cmdlen;i++)
		{
			if(tcmd[i] == ' ')
			{
				tcmd[i] = '\0';
				cmd[j++] = &tcmd[i+1];
			}
			if(tcmd[i] == '\n') 
			{
				tcmd[i] = '\0';
			}
		}
		if((*cmd[0] == 'q') || (*cmd[0] == 'Q'))
			return 0;
		cmd[j++] = NULL;
		if((tpid=fork()) != EOF)
		{
			if(tpid == 0)
			{
				//执行命令
				if(execvp(cmd[0],cmd) == -1)
					perror("execvp");
				return 0;
			}
			else
			{
				//回收子进程
				if(wait(&twstatus) == -1)
					perror("wait");
			}
		}
	}
	return 0;
}
