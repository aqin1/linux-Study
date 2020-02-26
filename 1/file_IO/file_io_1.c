#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

char buf[] = "This is a test file of file IO!";
char buf2[1024];

int main(int argc,char *argv[])
{
	int fd;
//	long fp;
	//O_CREAT 文件不存在就创建文件
	//S_IWUSR S_IRUSR 分别是所有者的写，读权限
	fd = open("a.txt",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	if(fd == -1)
	{
		perror("open");
		return -fd;
	}
	if(lseek(fd,0,SEEK_END) == -1)
		perror("lseek");
	if(write(fd,buf,sizeof(buf)) == -1)
		perror("write");
	else
		printf("write file succeed!\n");
//	fp = ftell(fd,0,SEEK_END);
//	if(fp == -1)
//		perror("ftell");
//	else
//		printf("File size is %ld\n",fp);
	lseek(fd,0,SEEK_SET);
	if(read(fd,buf2,strlen(buf)) == -1)
		perror("read");
	else
		printf("Read with file is %s\n",buf2);
	close(fd);
	
	return 0;
}	
