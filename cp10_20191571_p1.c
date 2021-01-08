#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool freePrint(char str[],int strSize,FILE* fp);

int main()
{
	int N;

	scanf("%d\n",&N);
	char* str= (char*)malloc(sizeof(char)*257);


	FILE*fp=fopen("output.txt","w");

	fgets(str,(N+1)*sizeof(char),stdin);

	freePrint(str,N,fp);

	
	free(str);


	return 0;
}

bool freePrint(char str[],int strSize,FILE* fp)
{
	
	str[strSize]='\0';
	fputs(str,stdout);
	printf("\n");
	fputs(str,fp);
	fclose(fp);
	return true;
	
}
