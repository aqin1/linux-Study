#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc,char* argv[])
{
	//extern int errno;
	FILE *file_1;
	file_1 = fopen("b.txt","r+");
	if(file_1 == NULL)
	{
		perror("fopen");
		printf("%s\n",strerror(errno));
		return -1;
	}
	return 0;
}
