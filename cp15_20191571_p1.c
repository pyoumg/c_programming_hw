#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{
	char *str1;
	char *str2;
	char *str3;

}firstString;

typedef struct
{
	char *str1;
	char *str2;
	char *str3;



}secondString;

int main()
{
		firstString n1;
		secondString n2;

		int a,b;
		char stra[11];
		n1.str1=(char*)malloc(sizeof(char)*6);
		n1.str2=(char*)malloc(sizeof(char)*6);
		n1.str3=(char*)malloc(sizeof(char)*6);
		n2.str1=(char*)malloc(sizeof(char)*6);
		n2.str2=(char*)malloc(sizeof(char)*6);
		n2.str3=(char*)malloc(sizeof(char)*6);
		scanf("%d %d",&a,&b);
		strcpy(n1.str1,"one");
		strcpy(n1.str2,"two");
		strcpy(n1.str3,"three");
		strcpy(n2.str1,"one");
		strcpy(n2.str2,"two");
		strcpy(n2.str3,"three");
		
		if(a==1)
		{
				strcpy(stra,n1.str1);
		}
		else if(a==2)
		{
			strcpy(stra,n1.str2);
		}
		else
		{
			strcpy(stra,n1.str3);
		}

		if(b==1)
		{
			strcat(stra,n2.str1);

		}

		else if( b==2)
		{
				strcat(stra,n2.str2);
		}
		else 
		{
				strcat(stra,n2.str3);
		}
		
		
		printf("%s\n",stra);
		free(n1.str1);
		free(n1.str2);
		free(n1.str3);
		free(n2.str1);
		free(n2.str2);
		free(n2.str3);
	return 0;
}
