#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int fd;
	//O_CREAT 文件不存在就创建文件
	//S_IWUSR S_IRUSR 分别是所有者的写，读权限
	open("a.txt",O_CREAT,S_IWUSR|S_IWUSR);
	
	return 0;
}	
