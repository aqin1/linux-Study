#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

int set_serialattr(int tfd,struct termios *ter_ptr,speed_t ser_sp)
{
	//设置波特率
	cfsetispeed(ter_ptr,ser_sp);
	cfsetospeed(ter_ptr,ser_sp);
	//设置数据位
	ter_ptr->c_cflag &= ~CSIZE;
	ter_ptr->c_cflag |= CS8;
	//设置奇偶校验
	ter_ptr->c_cflag &= ~PARENB;
	//设置停止位
	ter_ptr->c_cflag &= ~CSTOPB;
	//激活选项
	ter_ptr->c_cflag |= CLOCAL | CREAD;
	//设置最少字符和等待时间
	ter_ptr->c_cc[VTIME] = 20;
	ter_ptr->c_cc[VMIN] = 0;
	//设置输出
	ter_ptr->c_oflag = 0;
	ter_ptr->c_oflag &= ~OPOST;
	//选择原始模式
	cfmakeraw(ter_ptr);
	//刷新缓冲区
	tcflush(tfd,TCIOFLUSH);
	//保存串口属性
	if(tcsetattr(tfd,TCSANOW,ter_ptr) == -1)
		perror("tcsetattr_new");
	return 0;	
}

int main(int agrc,char *agrv[])
{
	struct termios new_ter_p,old_ter_p;
	char buff[] = "I am aqin";
	char tempbuff[20] = "";
	int fd;
	int err;
	fd = open("/dev/ttyS1",O_RDWR | O_NOCTTY | O_NDELAY);
	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	if(fcntl(fd,F_SETFL,0) == -1)
		perror("fcntl");

	if(!isatty(fd))
		printf("No a TTY!\n");
	if(tcgetattr(fd,&old_ter_p) == -1)
		perror("tcgetattr");
	set_serialattr(fd,&new_ter_p,115200);
	if(write(fd,buff,sizeof(buff)) == -1)
		perror("write");
	if(read(fd,tempbuff,sizeof(buff)) == -1)
		perror("read");
	else
		printf("%s\n",tempbuff);
	if(tcsetattr(fd,TCSANOW,&old_ter_p) == -1)
		perror("tcsetattr_old");
	return 0;
}
