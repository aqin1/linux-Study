#include <stdio.h>
#include <string.h>
int main(int argc,char* argv[])
{
	FILE *file;
//	char p[100] = "";
	char *pp;
	file = fopen("../a.txt","a+");
	if(file == NULL)
		printf("open file error!\n");
	else
	{
		printf("Please Input something to the file:");
		scanf("%s",pp);
		printf("%s\n",pp);
	//	printf("strlen(pp)=%ld",strlen(pp));
	//	fwrite(p,sizeof(p),1,file);
	//	fread(pp,sizeof(p),1,file);
	//	printf("%s",pp);
	}
	return 0;
}
