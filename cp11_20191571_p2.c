#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int my_atoi(const char*);
int main()
{
	
	char str[60];
		
	scanf("%s",str);
	int n=strlen(str);
	str[n]='\0';

	int num=my_atoi(str);
	printf("%d\n",num);


	return 0;
}

int my_atoi(const char* str)
{
	int num=0,i=0,sign=1,flag=0;

	while(str[i]!='\0')
	{
			
		num=num*10+(str[i]-'0');
		i++;

	}	
	return num;
}
