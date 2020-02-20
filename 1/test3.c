#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc,char* argv[])
{
	int fd1,fd2;
	fd1 = open("../a.txt",O_RDONLY);
	printf("%d\n",fd1);
	fd2 = open("../b.txt",O_RDONLY);
	printf("%d\n",fd2);

	close(fd1);
	close(fd2);

	return 0;
}
