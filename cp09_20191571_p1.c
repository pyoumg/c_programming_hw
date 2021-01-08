#include <stdio.h>
#include <stdlib.h>
char* flip_and_return(char* origin, int x, int y);

int main()
{
	int x,y;
	char* ori=(char*)malloc(sizeof(char)*11);
	char* change;
	scanf("%s ",ori);
	scanf("%d %d",&x,&y);
	change= flip_and_return(ori,x,y);
	printf("%s\n",change);

	free(change);
	free(ori);
	return 0;
}

char* flip_and_return(char* origin,int x,int y)
{
	char* change=(char*)malloc(sizeof(char)*11);
	int j=y-x;
	for(int i=x;i<(y+1);i++)
		{
			*(change+j)=*(origin+i);
			j=j-1;
		}
	*(change+y-x+1)='\0';
	return change;


	
}
